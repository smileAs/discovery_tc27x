/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2018-08-21 08:49:56
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#define CAN_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_Can_0857 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[3] = {
  /* Index    CanIfChannelId      Comment */
  /*     0 */             0U,  /* [CT_CAN00_388e5969] */
  /*     1 */             1U,  /* [CT_CAN01_388e5969] */
  /*     2 */             2U   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                         Description
  CanControllerDefaultBaudrate
  RxBasicHandleMax            
  RxBasicHandleStart          
  RxBasicHandleStop           
  RxBasicHwStart              
  RxBasicHwStop               
  RxFullHandleMax             
  RxFullHandleStart           
  RxFullHandleStop            
  RxFullHwStart               
  RxFullHwStop                
  TxBasicHandleMax            
  TxBasicHandleStart          
  TxBasicHandleStop           
  TxBasicHwStart              
  TxBasicHwStop               
  TxFullHandleMax             
  TxFullHandleStart           
  TxFullHandleStop            
  TxFullHwStart               
  TxFullHwStop                
  UnusedHandleMax             
  UnusedHandleStart           
  UnusedHandleStop            
  UnusedHwStart               
  UnusedHwStop                
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[3] = {
    /* Index    CanControllerDefaultBaudrate  RxBasicHandleMax  RxBasicHandleStart  RxBasicHandleStop  RxBasicHwStart  RxBasicHwStop  RxFullHandleMax  RxFullHandleStart  RxFullHandleStop  RxFullHwStart  RxFullHwStop  TxBasicHandleMax  TxBasicHandleStart  TxBasicHandleStop  TxBasicHwStart  TxBasicHwStop  TxFullHandleMax  TxFullHandleStart  TxFullHandleStop  TxFullHwStart  TxFullHwStop  UnusedHandleMax  UnusedHandleStart  UnusedHandleStop  UnusedHwStart  UnusedHwStop        Comment */
  { /*     0 */                         500U,               1U,                 1U,                2U,             1U,            3U,              0U,                1U,               1U,            1U,           1U,               1U,                 0U,                1U,             0U,            1U,              0U,                0U,               0U,            0U,           0U,              1U,                6U,               7U,            3U,           7U },  /* [CT_CAN00_388e5969] */
  { /*     1 */                         500U,               1U,                 3U,                4U,             8U,            9U,              0U,                3U,               3U,            8U,           8U,               1U,                 2U,                3U,             7U,            8U,              0U,                0U,               0U,            7U,           7U,              1U,                7U,               8U,            9U,          14U },  /* [CT_CAN01_388e5969] */
  { /*     2 */                         500U,               1U,                 5U,                6U,            15U,           16U,              0U,                5U,               5U,           15U,          15U,               1U,                 4U,                5U,            14U,           15U,              0U,                0U,               0U,           14U,          14U,              1U,                8U,               9U,           16U,          21U }   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_GlobalInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_GlobalInterruptPendingMask
  \brief  Mask of all interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_GlobalInterruptPendingMaskType, CAN_CONST) Can_GlobalInterruptPendingMask[24] = {
  /* Index    GlobalInterruptPendingMask      Comment */
  /*     0 */               0x00000007UL,  /* [CT_CAN00_388e5969, Mailbox 0-31] */
  /*     1 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 32-63] */
  /*     2 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 64-95] */
  /*     3 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 96-127] */
  /*     4 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 128-159] */
  /*     5 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 160-191] */
  /*     6 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 192-223] */
  /*     7 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 224-255] */
  /*     8 */               0x00000180UL,  /* [CT_CAN01_388e5969, Mailbox 0-31] */
  /*     9 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 32-63] */
  /*    10 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 64-95] */
  /*    11 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 96-127] */
  /*    12 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 128-159] */
  /*    13 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 160-191] */
  /*    14 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 192-223] */
  /*    15 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 224-255] */
  /*    16 */               0x0000C000UL,  /* [CT_CAN02_388e5969, Mailbox 0-31] */
  /*    17 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 32-63] */
  /*    18 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 64-95] */
  /*    19 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 96-127] */
  /*    20 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 128-159] */
  /*    21 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 160-191] */
  /*    22 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 192-223] */
  /*    23 */               0x00000000UL   /* [CT_CAN02_388e5969, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitBT
**********************************************************************************************************************/
/** 
  \var    Can_InitBT
  \brief  Bit timing.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitBTType, CAN_CONST) Can_InitBT[3] = {
  /* Index    InitBT       Comment */
  /*     0 */ 0x4DC7U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig] */
  /*     1 */ 0x4DC7U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig] */
  /*     2 */ 0x4DC7U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeH
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitCodeHType, CAN_CONST) Can_InitCodeH[3] = {
  /* Index    InitCodeH      Comment */
  /*     0 */   0x0000U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */   0x0000U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     2 */   0x0000U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeL
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitCodeLType, CAN_CONST) Can_InitCodeL[3] = {
  /* Index    InitCodeL      Comment */
  /*     0 */   0x0000U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */   0x0000U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     2 */   0x0000U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskH
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitMaskHType, CAN_CONST) Can_InitMaskH[3] = {
  /* Index    InitMaskH      Comment */
  /*     0 */   0x2000U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */   0x2000U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     2 */   0x2000U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskL
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitMaskLType, CAN_CONST) Can_InitMaskL[3] = {
  /* Index    InitMaskL      Comment */
  /*     0 */   0x0000U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */   0x0000U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     2 */   0x0000U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig, CanFilterMask] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[3] = {
  /* Index    InitObjectBaudrate      Comment */
  /*     0 */               500U,  /* [CT_CAN00_388e5969 - CanControllerBaudrateConfig] */
  /*     1 */               500U,  /* [CT_CAN01_388e5969 - CanControllerBaudrateConfig] */
  /*     2 */               500U   /* [CT_CAN02_388e5969 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct'  / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[4] = {
  /* Index    InitObjectStartIndex      Comment */
  /*     0 */                   0U,  /* [CT_CAN00_388e5969] */
  /*     1 */                   1U,  /* [CT_CAN01_388e5969] */
  /*     2 */                   2U,  /* [CT_CAN02_388e5969] */
  /*     3 */                   3U   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitPortSel
**********************************************************************************************************************/
/** 
  \var    Can_InitPortSel
  \brief  Receive input selection.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitPortSelType, CAN_CONST) Can_InitPortSel[3] = {
  /* Index    InitPortSel      Comment */
  /*     0 */          3U,  /* [CT_CAN00_388e5969] */
  /*     1 */          4U,  /* [CT_CAN01_388e5969] */
  /*     2 */          1U   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for all controller interrupts.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_IsrOsIdType, CAN_CONST) Can_IsrOsId[3] = {
  /* Index    IsrOsId       Comment */
  /*     0 */CanIsr_0 ,  /* [CT_CAN00_388e5969 / Node0] */
  /*     1 */CanIsr_1 ,  /* [CT_CAN01_388e5969 / Node1] */
  /*     2 */CanIsr_2    /* [CT_CAN02_388e5969 / Node2] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element          Description
  IDValue      
  DLC_FIFO     
  HwHandle     
  MailboxType  
  MaxDataLen   
  MsgController
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[9] = {
    /* Index    IDValue  DLC_FIFO  HwHandle  MailboxType                                MaxDataLen  MsgController        Comment */
  { /*     0 */ 0x0000U,       1U,       0U, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            0U },  /* [CN_CAN00_388e5969_Tx_Std] */
  { /*     1 */ 0x0000U,       2U,       1U, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            0U },  /* [CN_CAN00_388e5969_Rx_Std] */
  { /*     2 */ 0x0000U,       1U,       7U, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            1U },  /* [CN_CAN01_388e5969_Tx_Std] */
  { /*     3 */ 0x0000U,       1U,       8U, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            1U },  /* [CN_CAN01_388e5969_Rx_Std] */
  { /*     4 */ 0x0000U,       1U,      14U, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            2U },  /* [CN_CAN02_388e5969_Tx_Std] */
  { /*     5 */ 0x0000U,       1U,      15U, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U,            2U },  /* [CN_CAN02_388e5969_Rx_Std] */
  { /*     6 */ 0x0000U,       4U,       3U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U,            0U },  /* [] */
  { /*     7 */ 0x0000U,       5U,       9U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U,            1U },  /* [] */
  { /*     8 */ 0x0000U,       5U,      16U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U,            2U }   /* [] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeAdr
**********************************************************************************************************************/
/** 
  \var    Can_NodeAdr
  \brief  Physical node address.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_NodeAdrType, CAN_CONST) Can_NodeAdr[3] = {
  /* Index    NodeAdr           Comment */
  /*     0 */ 0xF0018200UL,  /* [CT_CAN00_388e5969] */
  /*     1 */ 0xF0018300UL,  /* [CT_CAN01_388e5969] */
  /*     2 */ 0xF0018400UL   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeNum
**********************************************************************************************************************/
/** 
  \var    Can_NodeNum
  \brief  Physical node.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_NodeNumType, CAN_CONST) Can_NodeNum[3] = {
  /* Index    NodeNum      Comment */
  /*     0 */      0U,  /* [CT_CAN00_388e5969] */
  /*     1 */      1U,  /* [CT_CAN01_388e5969] */
  /*     2 */      2U   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_PhysPrio
**********************************************************************************************************************/
/** 
  \var    Can_PhysPrio
  \brief  Interrupt priority.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_PhysPrioType, CAN_CONST) Can_PhysPrio[8] = {
  /* Index    PhysPrio             Comment */
  /*     0 */             10U,  /* [Physical channel 0] */
  /*     1 */             10U,  /* [Physical channel 1] */
  /*     2 */             10U,  /* [Physical channel 2] */
  /*     3 */ CAN_NO_PHYSPRIO,  /* [dummy entry] */
  /*     4 */ CAN_NO_PHYSPRIO,  /* [dummy entry] */
  /*     5 */ CAN_NO_PHYSPRIO,  /* [dummy entry] */
  /*     6 */ CAN_NO_PHYSPRIO,  /* [dummy entry] */
  /*     7 */ CAN_NO_PHYSPRIO   /* [dummy entry] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxBasicInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxBasicInterruptPendingMask
  \brief  Mask of Rx BasicCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_RxBasicInterruptPendingMaskType, CAN_CONST) Can_RxBasicInterruptPendingMask[24] = {
  /* Index    RxBasicInterruptPendingMask      Comment */
  /*     0 */                0x00000006UL,  /* [CT_CAN00_388e5969, Mailbox 0-31] */
  /*     1 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 32-63] */
  /*     2 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 64-95] */
  /*     3 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 96-127] */
  /*     4 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 128-159] */
  /*     5 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 160-191] */
  /*     6 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 192-223] */
  /*     7 */                0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 224-255] */
  /*     8 */                0x00000100UL,  /* [CT_CAN01_388e5969, Mailbox 0-31] */
  /*     9 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 32-63] */
  /*    10 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 64-95] */
  /*    11 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 96-127] */
  /*    12 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 128-159] */
  /*    13 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 160-191] */
  /*    14 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 192-223] */
  /*    15 */                0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 224-255] */
  /*    16 */                0x00008000UL,  /* [CT_CAN02_388e5969, Mailbox 0-31] */
  /*    17 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 32-63] */
  /*    18 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 64-95] */
  /*    19 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 96-127] */
  /*    20 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 128-159] */
  /*    21 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 160-191] */
  /*    22 */                0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 192-223] */
  /*    23 */                0x00000000UL   /* [CT_CAN02_388e5969, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxFullInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxFullInterruptPendingMask
  \brief  Mask of Rx FullCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_RxFullInterruptPendingMaskType, CAN_CONST) Can_RxFullInterruptPendingMask[24] = {
  /* Index    RxFullInterruptPendingMask      Comment */
  /*     0 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 0-31] */
  /*     1 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 32-63] */
  /*     2 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 64-95] */
  /*     3 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 96-127] */
  /*     4 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 128-159] */
  /*     5 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 160-191] */
  /*     6 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 192-223] */
  /*     7 */               0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 224-255] */
  /*     8 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 0-31] */
  /*     9 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 32-63] */
  /*    10 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 64-95] */
  /*    11 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 96-127] */
  /*    12 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 128-159] */
  /*    13 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 160-191] */
  /*    14 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 192-223] */
  /*    15 */               0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 224-255] */
  /*    16 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 0-31] */
  /*    17 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 32-63] */
  /*    18 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 64-95] */
  /*    19 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 96-127] */
  /*    20 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 128-159] */
  /*    21 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 160-191] */
  /*    22 */               0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 192-223] */
  /*    23 */               0x00000000UL   /* [CT_CAN02_388e5969, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_SrcNum
**********************************************************************************************************************/
/** 
  \var    Can_SrcNum
  \brief  Interrupt source register.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_SrcNumType, CAN_CONST) Can_SrcNum[3] = {
  /* Index    SrcNum      Comment */
  /*     0 */     0U,  /* [CT_CAN00_388e5969] */
  /*     1 */     1U,  /* [CT_CAN01_388e5969] */
  /*     2 */     2U   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_TxInterruptPendingMask
  \brief  Mask of Tx interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_TxInterruptPendingMaskType, CAN_CONST) Can_TxInterruptPendingMask[24] = {
  /* Index    TxInterruptPendingMask      Comment */
  /*     0 */           0x00000001UL,  /* [CT_CAN00_388e5969, Mailbox 0-31] */
  /*     1 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 32-63] */
  /*     2 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 64-95] */
  /*     3 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 96-127] */
  /*     4 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 128-159] */
  /*     5 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 160-191] */
  /*     6 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 192-223] */
  /*     7 */           0x00000000UL,  /* [CT_CAN00_388e5969, Mailbox 224-255] */
  /*     8 */           0x00000080UL,  /* [CT_CAN01_388e5969, Mailbox 0-31] */
  /*     9 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 32-63] */
  /*    10 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 64-95] */
  /*    11 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 96-127] */
  /*    12 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 128-159] */
  /*    13 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 160-191] */
  /*    14 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 192-223] */
  /*    15 */           0x00000000UL,  /* [CT_CAN01_388e5969, Mailbox 224-255] */
  /*    16 */           0x00004000UL,  /* [CT_CAN02_388e5969, Mailbox 0-31] */
  /*    17 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 32-63] */
  /*    18 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 64-95] */
  /*    19 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 96-127] */
  /*    20 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 128-159] */
  /*    21 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 160-191] */
  /*    22 */           0x00000000UL,  /* [CT_CAN02_388e5969, Mailbox 192-223] */
  /*    23 */           0x00000000UL   /* [CT_CAN02_388e5969, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxOffsetHwToLog
**********************************************************************************************************************/
/** 
  \var    Can_TxOffsetHwToLog
  \brief  tx hardware to logical handle indirection table
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_TxOffsetHwToLogType, CAN_CONST) Can_TxOffsetHwToLog[3] = {
  /* Index    TxOffsetHwToLog      Comment */
  /*     0 */               0,  /* [CT_CAN00_388e5969] */
  /*     1 */              -6,  /* [CT_CAN01_388e5969] */
  /*     2 */             -12   /* [CT_CAN02_388e5969] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendPdu
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendPdu
  \brief  temporary pduId buffer for send mailbox
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ActiveSendPduType, CAN_VAR_NOINIT) Can_ActiveSendPdu[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendState
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendState
  \brief  temporary send state buffer for send mailbox
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ActiveSendStateType, CAN_VAR_NOINIT) Can_ActiveSendState[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_BusOffNotified
**********************************************************************************************************************/
/** 
  \var    Can_BusOffNotified
  \brief  Controls BusOff notifications.
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_BusOffNotifiedType, CAN_VAR_NOINIT) Can_BusOffNotified[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanInterruptCounter
**********************************************************************************************************************/
/** 
  \var    Can_CanInterruptCounter
  \brief  CAN interrupt disable counter for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Can_CanInterruptCounterType, CAN_VAR_NOINIT) Can_CanInterruptCounter[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanInterruptOldStatus
**********************************************************************************************************************/
/** 
  \var    Can_CanInterruptOldStatus
  \brief  last CAN interrupt status for restore interrupt for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(tCanLLCanIntOld, CAN_VAR_NOINIT) Can_CanInterruptOldStatus[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Halt
**********************************************************************************************************************/
/** 
  \var    Can_Halt
  \brief  Reflects halt status of the controller.
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_HaltType, CAN_VAR_NOINIT) Can_Halt[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsBusOff
**********************************************************************************************************************/
/** 
  \var    Can_IsBusOff
  \brief  CAN state for each controller: busoff occur
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Can_IsBusOffType, CAN_VAR_NOINIT) Can_IsBusOff[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsHardwareCanceled
**********************************************************************************************************************/
/** 
  \var    Can_IsHardwareCanceled
  \brief  hw loop timeout occur for controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_IsHardwareCanceledType, CAN_VAR_NOINIT) Can_IsHardwareCanceled[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LastInitObject
**********************************************************************************************************************/
/** 
  \var    Can_LastInitObject
  \brief  last set baudrate for reinit
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_LastInitObjectType, CAN_VAR_NOINIT) Can_LastInitObject[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LogStatus
**********************************************************************************************************************/
/** 
  \var    Can_LogStatus
  \brief  CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Can_LogStatusType, CAN_VAR_NOINIT) Can_LogStatus[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LoopTimeout
**********************************************************************************************************************/
/** 
  \var    Can_LoopTimeout
  \brief  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_LoopTimeout_dim_type, CAN_VAR_NOINIT) Can_LoopTimeout[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_StatusReq
**********************************************************************************************************************/
/** 
  \var    Can_StatusReq
  \brief  CAN state request for each controller: START=0x01, STOP=0x02, WAKEUP=0x08, SLEEP=0x80
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Can_StatusReqType, CAN_VAR_NOINIT) Can_StatusReq[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TmpRxMsgMailbox
**********************************************************************************************************************/
/** 
  \var    Can_TmpRxMsgMailbox
  \brief  Temporary buffer for received messages.
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(tCanTmpMsgObjStruct, CAN_VAR_NOINIT) Can_TmpRxMsgMailbox[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




