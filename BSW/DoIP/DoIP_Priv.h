/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DoIP_Priv.h
 *      Project:  TcpIp-Stack
 *       Module:  Diagnostic over Internet Protocol
 *    Generator:  -
 *
 *  Description:  Header file for private declarations of Diagnostic over IP
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#if !defined(DOIP_PRIV_H)
#define DOIP_PRIV_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SchM_DoIP.h"
#include "DoIP_Cfg.h"
#if ( defined(DOIP_DEV_ERROR_REPORT) && (STD_ON == DOIP_DEV_ERROR_REPORT) )
# include "Det.h"
#endif /* defined(DOIP_DEV_ERROR_REPORT) && (STD_ON == DOIP_DEV_ERROR_REPORT) */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DOIP_INSTANCE_ID                  0u

#if ( !defined(DOIP_VTCP_TX_QUEUE_REQ_CNT) )
# define DOIP_VTCP_TX_QUEUE_REQ_CNT       2u
#else
# if ( (DOIP_VTCP_TX_QUEUE_REQ_CNT < 0x01u) || (DOIP_VTCP_TX_QUEUE_REQ_CNT > 0xFFu) )
#  error "DoIP.h: value of DOIP_VTCP_TX_QUEUE_REQ_CNT was defined to an invalid value! Valid range is 0x01u-0xFFu."
# endif /* (DOIP_VTCP_TX_QUEUE_REQ_CNT < 0x01u) || (DOIP_VTCP_TX_QUEUE_REQ_CNT > 0xFFu) */
#endif /* !defined(DOIP_VTCP_TX_QUEUE_REQ_CNT) */

#if ( !defined(DOIP_VTCP_RX_MULTI_MSG) )
# define DOIP_VTCP_RX_MULTI_MSG           STD_OFF
#else
# if ( (DOIP_VTCP_RX_MULTI_MSG != STD_ON) && (DOIP_VTCP_RX_MULTI_MSG != STD_OFF) )
#  error "DoIP.h: value of DOIP_VTCP_RX_MULTI_MSG was defined to an invalid value! Valid values are STD_ON/STD_OFF."
# endif /* (DOIP_VTCP_RX_MULTI_MSG != STD_ON) && (DOIP_VTCP_RX_MULTI_MSG != STD_OFF) */
#endif /* !defined(DOIP_VTCP_RX_MULTI_MSG) */

/**********************************************************************************************************************
 * DATA TYPE MACROS
 *********************************************************************************************************************/
/* PRQA S 3453,3458 FCT_LIKE_MACROS */ /* MD_MSR_19.4, MD_MSR_19.7 */
#define DOIP_A_P2VAR(Type)                (P2VAR(Type, AUTOMATIC, AUTOMATIC))
#define DOIP_A_P2CONST(Type)              (P2CONST(Type, AUTOMATIC, AUTOMATIC))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* critical section */
# define DOIP_BEGIN_CRITICAL_SECTION()   SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_0()
# define DOIP_END_CRITICAL_SECTION()     SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_0()

#define DOIP_DUMMY_STATEMENT_TYPE_VOID  0u
#define DOIP_DUMMY_STATEMENT_TYPE_VAR   1u

#if ( !defined(DOIP_DUMMY_STATEMENT_TYPE) )
# define DOIP_DUMMY_STATEMENT_VAR(v)    DOIP_DUMMY_STATEMENT(v)
#else
# if ( DOIP_DUMMY_STATEMENT_TYPE_VOID == DOIP_DUMMY_STATEMENT_TYPE )
#  define DOIP_DUMMY_STATEMENT_VAR(v)   (void)(v);
# else
#  define DOIP_DUMMY_STATEMENT_VAR(v)   (v)=(v);
# endif /* DOIP_DUMMY_STATEMENT_TYPE_VOID == DOIP_DUMMY_STATEMENT_TYPE */
#endif /* !defined(DOIP_DUMMY_STATEMENT_VAR) */

#define DOIP_GET_UINT8(Buffer, Offset, Variable)     ( (Variable) = (uint8)(Buffer)[(Offset)])

#define DOIP_GET_UINT16(Buffer, Offset, Variable)    ( (Variable) = (uint16)(((uint16)((Buffer)[(Offset)+0]) << 8) | \
                                                                      ((uint16)((Buffer)[(Offset)+1]))) )

#define DOIP_GET_UINT32(Buffer, Offset, Variable)    ( (Variable) = (uint32)(((uint32)((Buffer)[(Offset)+0]) << 24) | \
                                                                      ((uint32)((Buffer)[(Offset)+1]) << 16) | \
                                                                      ((uint32)((Buffer)[(Offset)+2]) <<  8) | \
                                                                      ((uint32)((Buffer)[(Offset)+3]))) )

/* Development Error Tracer */
#if ( defined(DOIP_DEV_ERROR_REPORT) && (STD_ON == DOIP_DEV_ERROR_REPORT) )
# define DOIP_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
          { \
            if (!(CONDITION)) \
            { \
              (void)Det_ReportError(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
              return; \
            } \
          }
# define DOIP_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
          { \
            if (!(CONDITION)) \
            { \
              (void)Det_ReportError(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
              return (RET_VAL); \
            } \
          }
# define DOIP_CheckDetErrorContinue(CONDITION, API_ID, ERROR_CODE) \
          { \
            if (!(CONDITION)) \
            { \
              (void)Det_ReportError(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
            } \
          }
# define DOIP_CallDetReportError(API_ID, ERROR_CODE) \
           (void)Det_ReportError(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (API_ID), (ERROR_CODE))
#else
# define DOIP_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
          { \
            if (!(CONDITION)) \
            { \
              return; \
            } \
          }
# define DOIP_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
          { \
            if (!(CONDITION)) \
            { \
              return (RET_VAL); \
            } \
          }
# define DOIP_CheckDetErrorContinue(CONDITION, API_ID, ERROR_CODE)
# define DOIP_CallDetReportError(API_ID, ERROR_CODE)
#endif /* defined(DOIP_DEV_ERROR_REPORT) && (STD_ON == DOIP_DEV_ERROR_REPORT) */

# if ( DOIP_CONFIGURATION_VARIANT_PRECOMPILE != DOIP_CONFIGURATION_VARIANT )
#  error "DoIP_Priv.h: Invalid DOIP_CONFIGURATION_VARIANT, (DOIP_CONFIGURATION_VARIANT_PRECOMPILE expected)"
# endif /* DOIP_CONFIGURATION_VARIANT_PRECOMPILE != DOIP_CONFIGURATION_VARIANT */

# define DOIP_CBK_STATIC

/* PRQA L:FCT_LIKE_MACROS */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (PRIVATE)
 *********************************************************************************************************************/
FUNC(void,            DOIP_CODE) DoIP_VHandleCloseSocketInUdpTxList(uint16 udpTxListIdx);
FUNC(Std_ReturnType,  DOIP_CODE) DoIP_VGetTesterIdxByTesterAddr(uint16 TesterAddr,
                               P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) TesterIdx);

#endif /* !defined(DOIP_PRIV_H) */

/**********************************************************************************************************************
 *  END OF FILE: DoIP_Priv.h
 *********************************************************************************************************************/
