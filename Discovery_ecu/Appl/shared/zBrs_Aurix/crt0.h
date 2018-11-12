#include <stdlib.h>
#include <string.h>
#include <machine/intrinsics.h>

#include <IfxScu_bf.h>
#include <IfxScu_reg.h>

typedef struct tagPllInitValue
{
	unsigned int uiOSCCON;
	unsigned int uiPLLCON0;
	unsigned int uiPLLCON1;
	unsigned int uiCCUCON0;
	unsigned int uiCCUCON1;
	unsigned int uiCCUCON2;
} TPllInitValue;

/** core special function registers */
#define CPU_CORE_ID                 (0xFE1C)
#define CPU_ISP                     (0xFE28)
#define CPU_BIV                     (0xFE20)
#define CPU_BTV                     (0xFE24)
#define CPU_PSW                     (0xFE04)
#define CPU_PCXI                    (0xFE00)
#define CPU_LCX                     (0xFE3C)
#define CPU_FCX                     (0xFE38)

#define IFX_CPU_CORE_ID_CORE_ID_MSK (0x7)
#define IFX_CPU_PSW_CDC_MSK         (0x7f)
#define IFX_CPU_PSW_CDC_OFF         (0)
#define IFX_CPU_PSW_CDE_MSK         (0x1)
#define IFX_CPU_PSW_CDE_OFF         (7)
#define IFX_CPU_PSW_GW_MSK          (0x1)
#define IFX_CPU_PSW_GW_OFF          (8)

/** Program Counter */
typedef struct Ifx_CPU_PC_Bits
{
    volatile unsigned int reserved_0:1;
    volatile unsigned int PC:31;                 /**< \brief [31:1] Program Counter (r) */
} Ifx_CPU_PC_Bits;

/** Program Counter */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_CPU_PC_Bits B;
} Ifx_CPU_PC;

/** Debug Status Register */
typedef struct Ifx_CPU_DBGSR_Bits
{
    volatile unsigned int DE:1;                  /**< \brief [0:0] Debug Enable (rh) */
    volatile unsigned int HALT:2;                /**< \brief [2:1] CPU Halt Request / Status Field (rwh) */
    volatile unsigned int SIH:1;                 /**< \brief [3:3] Suspend-in Halt (rh) */
    volatile unsigned int SUSP:1;                /**< \brief [4:4] Current State of the Core Suspend-Out Signal (rwh) */
    volatile unsigned int reserved_5:1;
    volatile unsigned int PREVSUSP:1;            /**< \brief [6:6] Previous State of Core Suspend-Out Signal (rh) */
    volatile unsigned int PEVT:1;                /**< \brief [7:7] Posted Event (rwh) */
    volatile unsigned int EVTSRC:5;              /**< \brief [12:8] Event Source (rh) */
    volatile unsigned int reserved_13:19;
} Ifx_CPU_DBGSR_Bits;

/** Debug Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_CPU_DBGSR_Bits B;
} Ifx_CPU_DBGSR;

#define CPU1_PC                     (*(volatile Ifx_CPU_PC*)0xF883FE08u)
#define CPU2_PC                     (*(volatile Ifx_CPU_PC*)0xF885FE08u)
#define CPU1_DBGSR                  (*(volatile Ifx_CPU_DBGSR*)0xF883FD00u)
#define CPU2_DBGSR                  (*(volatile Ifx_CPU_DBGSR*)0xF885FD00u)

#define GPT120_BASE                 0xF0002E00
#define GPT120_CLC                  *((volatile unsigned int*)(GPT120_BASE + 0x00))
