/*====================================================================
* TriCore Aurix Start up Code
*====================================================================*/
#include "Os_Cfg.h"

#if defined(OS_CFG_DERIVATIVE_TC2D5) || defined(OS_CFG_DERIVATIVE_TC274) || defined(OS_CFG_DERIVATIVE_TC275) || defined(OS_CFG_DERIVATIVE_TC277) || defined(OS_CFG_DERIVATIVE_TC275_STEPC) || defined(OS_CFG_DERIVATIVE_TC277_STEPC)
# define __TRICORE_NAME__  0x2700
#elif defined(OS_CFG_DERIVATIVE_TC297) || defined(OS_CFG_DERIVATIVE_TC298) || defined(OS_CFG_DERIVATIVE_TC299) || defined(OS_CFG_DERIVATIVE_TC297_STEPB) || defined(OS_CFG_DERIVATIVE_TC299_STEPB)
# define __TRICORE_NAME__  0x2900
#elif defined(OS_CFG_DERIVATIVE_TC264) || defined(OS_CFG_DERIVATIVE_TC265) || defined(OS_CFG_DERIVATIVE_TC264_STEPB) || defined(OS_CFG_DERIVATIVE_TC265_STEPB) || defined(OS_CFG_DERIVATIVE_TC267_STEPB)  || defined(OS_CFG_DERIVATIVE_TC267)
# define __TRICORE_NAME__  0x2600
#elif defined(OS_CFG_DERIVATIVE_TC242) || defined(OS_CFG_DERIVATIVE_TC243) || defined(OS_CFG_DERIVATIVE_TC244)
# define __TRICORE_NAME__  0x2400
#elif defined(OS_CFG_DERIVATIVE_TC233) || defined(OS_CFG_DERIVATIVE_TC234) || defined(OS_CFG_DERIVATIVE_TC237)
# define __TRICORE_NAME__  0x2300
#elif defined(OS_CFG_DERIVATIVE_TC222) || defined(OS_CFG_DERIVATIVE_TC223) || defined(OS_CFG_DERIVATIVE_TC224)
# define __TRICORE_NAME__  0x2200
#elif defined(OS_CFG_DERIVATIVE_TC211) || defined(OS_CFG_DERIVATIVE_TC212) || defined(OS_CFG_DERIVATIVE_TC213)
# define __TRICORE_NAME__  0x2100
#else
# error "The selected derivative is not supported!"
#endif

#include "crt0.h"

/*
 * Structures of the copy/clear tables
 * to initialise the data ram
 */
typedef struct cleartable
{
	unsigned long *base;	/* base address of this area */
	long size;				/* size of this area */
} ClearTable_t;

typedef struct copytable
{
	unsigned long *src;		/* base address of the initial data */
	unsigned long *dst;		/* destination address to copy to */
	long size;				/* size of the area to copy */
} CopyTable_t;

/*
 * the core initialisation structure
 */
typedef struct coreinit
{
	const ClearTable_t	*cleartable;	/* the clear table of this CPU */
	const CopyTable_t	*copytable;		/* the copy table */
	unsigned long		*istack;		/* the interrupt stack */
	unsigned long		*ustack;		/* the initial userstack */
	unsigned long		*smallA0;		/* base of the small data area with base A0 */
	unsigned long		*smallA1;		/* base of the small data area with base A1 */
	unsigned long		*smallA8;		/* base of the small data area with base A8 */
	unsigned long		*smallA9;		/* base of the small data area with base A9 */
	unsigned long		csaBase;		/* base address of the CSA area */
	unsigned long		csaSize;		/* size of the CSA area */
	volatile Ifx_SCU_WDTCPU_CON0 *wdtCon0;	/* watchdog register base (address of wdtcon0) */
	volatile Ifx_SCU_WDTCPU_CON1 *wdtCon1;	/* watchdog register base (address of wdtcon1) */
	int (*main)(int, char **);			/* the main function */
} CoreInit_t;

/*
 * the boot mode header description
 */
typedef struct bmhd
{
	void (*startAddress)(void);			/* the User Code Start Address */
	unsigned short		bmIndex;		/* the Boot Mode Index (BMI) */
	unsigned short		bmhdID;			/* the Boot Mode Header ID (0xb359) */
	unsigned long		chkStart;		/* Memory Range to be checked - Start Address */
	unsigned long		chkEnd;			/* Memory Range to be checked - End Address */
	unsigned long		crcRange;		/* Check Result for the Memory Range */
	unsigned long		invCrcRange;	/* Inverted Check Result for the Memory Range */
	unsigned long		crcHead;		/* Check Result of the ABM Header (0 ..  0x17) */
	unsigned long		invCrcHead;		/* Inverted Check Result of the ABM Header */
} BMHD_t;


/*
 * CSA structure
 */
typedef struct
{
	unsigned int reg[16];
} csa_t;

/*
 * PCXI register definition
 */
typedef union
{
	struct
	{
		unsigned int pcxo:16;
		unsigned int pcxs:4;
		unsigned int res:12;
	} bits;
	unsigned int reg;
} pcxi_t;


void _start(void);
void cstart(const CoreInit_t *) __attribute__ ((interrupt,noinline));
static void WDT_ClearEndinit(volatile unsigned int *wdtbase) __attribute__ ((always_inline));
static void WDT_SetEndinit(volatile unsigned int *wdtbase) __attribute__ ((always_inline));
static void clear_table_func(const ClearTable_t *table);
static void copy_table_func(const CopyTable_t *table);
static void init_csa(unsigned int csa_base, unsigned int csa_size) __attribute__ ((always_inline));
static void system_set_pll(const TPllInitValue* pPllInitValue);


/* declare symbol used by linker for memory map checking */
#define _STRINGIFY(x) #x

#define DECL_SYM(name,val)              \
  __asm (".global       " #name );        \
  __asm (".set  " #name "," _STRINGIFY(val));   \
  __asm (".type " #name ",@object");

DECL_SYM(__TRICORE_DERIVATE_NAME__,__TRICORE_NAME__)


/* the BMI header description at start of internal flash at 0xa0000000 */
/*********************************************************************************
 * startup code
 *********************************************************************************/
__asm (".section .bmhd.STARTUP");
__asm (".global _RESET");
__asm (".global _START");
__asm ("_RESET: .word 0x00000000");
__asm (".word 0xb3590070");
__asm (".word 0x00000000");
__asm (".word 0x00000000");
__asm (".word 0x00000000");
__asm (".word 0x00000000");
__asm (".word 0x791eb864");
__asm (".word 0x86e1479b");
/* we must make a jump to cached segment, why trap_tab follow */
__asm ("_START: movh.a %a10,hi:0xD000F000");
__asm ("  lea  %a10,[%a10]lo:0xD000F000");
__asm ("  movh.a %a15,hi:_start");
__asm ("  lea  %a15,[%a15]lo:_start");
__asm ("  ji %a15");


extern int main(void);
extern unsigned int __BIV_BASE_CORE0[];
extern unsigned int __BTV_BASE_CORE0[];
extern unsigned int __BIV_BASE_CORE1[];
extern unsigned int __BTV_BASE_CORE1[];
extern unsigned int __BIV_BASE_CORE2[];
extern unsigned int __BTV_BASE_CORE2[];

unsigned long dummy_stack[10];
const CopyTable_t dummy_copy_table =
{
   (unsigned long *)0,
   (unsigned long *)0,
   -1,
};
const ClearTable_t dummy_clear_table =
{
   (unsigned long *)0,
   -1,
};

/* provide compiler information: symbols are not small addressable */
extern const ClearTable_t __clear_table;
extern const CopyTable_t  __copy_table;
extern const ClearTable_t __clear_table_CPU0_;
extern const CopyTable_t  __copy_table_CPU0_;
extern unsigned long    _SMALL_DATA__CPU0_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA2__CPU0_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA3__CPU0_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA4__CPU0_ __attribute__ ((weak));
extern unsigned long    __CSA_BEGIN_CPU0_;
extern unsigned long    __CSA_SIZE_CPU0_;
extern int init_applproc0()
{
  main();
  return 0;
}

extern const ClearTable_t __clear_table_CPU1_;
extern const CopyTable_t  __copy_table_CPU1_;
extern unsigned long    _SMALL_DATA__CPU1_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA2__CPU1_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA3__CPU1_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA4__CPU1_ __attribute__ ((weak));
extern unsigned long    __CSA_BEGIN_CPU1_;
extern unsigned long    __CSA_SIZE_CPU1_;
extern int init_applproc1()
{
  main();
  return 0;
}

extern const ClearTable_t __clear_table_CPU2_;
extern const CopyTable_t  __copy_table_CPU2_;
extern unsigned long    _SMALL_DATA__CPU2_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA2__CPU2_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA3__CPU2_ __attribute__ ((weak));
extern unsigned long    _SMALL_DATA4__CPU2_ __attribute__ ((weak));
extern unsigned long    __CSA_BEGIN_CPU2_;
extern unsigned long    __CSA_SIZE_CPU2_;
extern int init_applproc2()
{
  main();
  return 0;
}

/* provide compiler information: symbols are not small addressable */
#pragma section ".rodata.STARTUP" a
const CoreInit_t CPUInit[3] =
{
  [0] =
  {
    .cleartable = &dummy_clear_table,
    .copytable  = &dummy_copy_table,
    .istack   = dummy_stack,
    .ustack   = dummy_stack,
    .smallA0  = &_SMALL_DATA__CPU0_,
    .smallA1  = &_SMALL_DATA2__CPU0_,
    .smallA8  = &_SMALL_DATA3__CPU0_,
    .smallA9  = &_SMALL_DATA4__CPU0_,
    .csaBase  = (unsigned long)&__CSA_BEGIN_CPU0_,
    .csaSize  = (unsigned long)&__CSA_SIZE_CPU0_,
    .wdtCon0  = &SCU_WDTCPU0CON0,
    .wdtCon1  = &SCU_WDTCPU0CON1,
    .main   = init_applproc0,
  },

  [1] =
  {
    .cleartable = &dummy_clear_table,
    .copytable  = &dummy_copy_table,
    .istack   = dummy_stack,
    .ustack   = dummy_stack,
    .smallA0  = &_SMALL_DATA__CPU1_,
    .smallA1  = &_SMALL_DATA2__CPU1_,
    .smallA8  = &_SMALL_DATA3__CPU1_,
    .smallA9  = &_SMALL_DATA4__CPU1_,
    .csaBase  = (unsigned long)&__CSA_BEGIN_CPU1_,
    .csaSize  = (unsigned long)&__CSA_SIZE_CPU1_,
    .wdtCon0  = &SCU_WDTCPU1CON0,
    .wdtCon1  = &SCU_WDTCPU1CON1,
    .main   = init_applproc1,
  },

  [2] =
  {
    .cleartable = &dummy_clear_table,
    .copytable  = &dummy_copy_table,
    .istack   = dummy_stack,
    .ustack   = dummy_stack,
    .smallA0  = &_SMALL_DATA__CPU2_,
    .smallA1  = &_SMALL_DATA2__CPU2_,
    .smallA8  = &_SMALL_DATA3__CPU2_,
    .smallA9  = &_SMALL_DATA4__CPU2_,
    .csaBase  = (unsigned long)&__CSA_BEGIN_CPU2_,
    .csaSize  = (unsigned long)&__CSA_SIZE_CPU2_,
    .wdtCon0  = &SCU_WDTCPU2CON0,
    .wdtCon1  = &SCU_WDTCPU2CON1,
    .main   = init_applproc2,
  }
};


static Ifx_SCU * const pSCU = (Ifx_SCU *)&MODULE_SCU;

/* 100/50 MHz @ 20MHz ext. clock */
const TPllInitValue g_PllInitValue_100_50 =
{
	/* OSCCON,	PLLCON0,	PLLCON1,	CCUCON0,	CCUCON1,	CCUCON2 */
	0x00070118, 0x00015E20, 0x00020005, 0x52220121, 0x50212212, 0x40000202
};
#pragma section

#pragma section ".text.STARTUP" ax 4
void _start(void)
{
  unsigned int coreID = _mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK;
  const CoreInit_t *core;   /* the core initialisation structure */
  core = &CPUInit[coreID];
  
  cstart(core);
}

/*
 * the initial startup routine
 * - initialise the global RAM
 * - start the other CPUs
 * - disable/enable System Watchdog
 * - call the main function
 */
void cstart(const CoreInit_t *core)
{
  unsigned int psw;

  /* reset endinit and disable watchdog */
  if (core->wdtCon0->U & 1)
  {
    /* clear endinit bit in CPU0 WDT */
    WDT_ClearEndinit(&core->wdtCon0->U);
  }
  if ((core == &CPUInit[0]) && (*&SCU_WDTSCON0.U & 1))
  {
    /* clear endinit bit in safety WDT */
    WDT_ClearEndinit(&SCU_WDTSCON0.U);
  }

  /* setup interrupt stack */
  _mtcr(CPU_ISP, (unsigned int)core->istack);

  if (core == &CPUInit[0])
  {
     _mtcr(CPU_BIV, (unsigned int)__BIV_BASE_CORE0);

     /* install trap handlers */
     _mtcr(CPU_BTV, (unsigned int)__BTV_BASE_CORE0);
  }else if (core == &CPUInit[1])
  {
     _mtcr(CPU_BIV, (unsigned int)__BIV_BASE_CORE1);

     /* install trap handlers */
     _mtcr(CPU_BTV, (unsigned int)__BTV_BASE_CORE1);
  }else if (core == &CPUInit[2])
  {
     _mtcr(CPU_BIV, (unsigned int)__BIV_BASE_CORE2);

     /* install trap handlers */
     _mtcr(CPU_BTV, (unsigned int)__BTV_BASE_CORE2);
  }
  
  _isync();

  /* initialise call depth counter */
  psw  = _mfcr(CPU_PSW);
  psw |= IFX_CPU_PSW_CDC_MSK;
  psw &= ~(IFX_CPU_PSW_CDE_MSK << IFX_CPU_PSW_CDE_OFF);
  _mtcr(CPU_PSW, psw);
  _isync();

  /* enable write access to system global registers */
  psw  = _mfcr(CPU_PSW);
  psw |= (IFX_CPU_PSW_GW_MSK << IFX_CPU_PSW_GW_OFF);
  _mtcr(CPU_PSW, psw);
  _isync();

  /* initialise SDA base pointers */
  __asm volatile ("mov.aa %%a0, %0" : : "a" (core->smallA0));
  __asm volatile ("mov.aa %%a1, %0" : : "a" (core->smallA1));
  __asm volatile ("mov.aa %%a8, %0" : : "a" (core->smallA8));
  __asm volatile ("mov.aa %%a9, %0" : : "a" (core->smallA9));

  /* disable write access to system global registers */
  psw  = _mfcr(CPU_PSW);
  psw &= ~(IFX_CPU_PSW_GW_MSK << IFX_CPU_PSW_GW_OFF);
  _mtcr(CPU_PSW, psw);
  _isync();

  GPT120_CLC = 0;

  /* disable Watchdogs */
  if (core == &CPUInit[0])
  {
    /* safety WDT handled by CPU0 */
    SCU_WDTSCON1.B.DR = 1;
    WDT_SetEndinit(&SCU_WDTSCON0.U);
  }

  core->wdtCon1->B.DR = 1;
  WDT_SetEndinit(&core->wdtCon0->U);

  init_csa(core->csaBase, core->csaSize);

  /* handle global clear and copy tables */
  if (core == &CPUInit[0])
  {
    clear_table_func(&__clear_table);
    copy_table_func(&__copy_table);
  }

  /* handle core specific clear and copy tables */
  clear_table_func(core->cleartable);
  copy_table_func(core->copytable);
  
  /* set PLL */
  system_set_pll(&g_PllInitValue_100_50);
  
  WDT_ClearEndinit(&SCU_WDTSCON0.U);

  *(volatile unsigned long*)(0xF0000000+0xE8) = (unsigned long)0x12000000;
 
  *(volatile unsigned long*)(0xF0000100+0xE8) = (unsigned long)0x12000000;
 
  *(volatile unsigned long*)(0xF0000200+0xE8) = (unsigned long)0x12000000;
  WDT_SetEndinit(&SCU_WDTSCON0.U);


  /* pass coreID to main */
  /* core->ustack[-2] = _mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK; */
  /* terminate argv */
  /* core->ustack[-1] = 0; */
  /* __asm volatile ("mov.aa %%sp, %0" : : "a" (&core->ustack[-2]) : "a10"); */
  /* call main program, pass return code to C99 function _Exit */
  /* _Exit is exit without atexit handling (reduced C library overhead) */
  (*core->main)(1, (char **)&core->ustack[0]);
}

static void WDT_ClearEndinit(volatile unsigned int *wdtbase)
{
  unsigned int passwd;

  passwd = *wdtbase;
  passwd &= 0xffffff00;
  *wdtbase = passwd | 0xf1;
  *wdtbase = passwd | 0xf2;
  /* read back new value ==> synchronise LFI */
  (void)*wdtbase;
}
static inline void WDT_SetEndinit(volatile unsigned int *wdtbase)
{
  unsigned int passwd;

  passwd = *wdtbase;
  passwd &= 0xffffff00;
  *wdtbase = passwd | 0xf1;
  *wdtbase = passwd | 0xf3;
  /* read back new value ==> synchronise LFI */
  (void)*wdtbase;
}

static void clear_table_func(const ClearTable_t *pt)
{
  while (pt->size >= 0)
  {
    memset(pt->base, 0l, pt->size);
    pt++;
  }
}

static void copy_table_func(const CopyTable_t *pt)
{
  while (pt->size >= 0)
  {
    memcpy(pt->dst, pt->src, pt->size);
    pt++;
  }
}

#define CSA_FRAME_SIZE  64
#define CSA_ALIGNMENT (CSA_FRAME_SIZE - 1)

static void init_csa(unsigned int csa_base, unsigned int csa_size)
{
  csa_t   *pcsa;
  pcxi_t    pcxi;
  unsigned int current_csa;
  unsigned int reservedCSAs = 15;
  unsigned int LCXIsSet = 0;

  _mtcr(CPU_PCXI, 0);           /* initialise PCXI */

  /* force correct alignment of CSA */
  csa_base = (csa_base + CSA_ALIGNMENT) & ~CSA_ALIGNMENT;
  csa_size = csa_size / CSA_FRAME_SIZE;   /* number of csa entries */

  pcsa = (csa_t *)csa_base;

  pcsa->reg[0] = 0;
  pcsa++;
  current_csa = csa_base;

  pcxi.bits.pcxs = csa_base >> 28;      /* segment of csa area */
  pcxi.bits.pcxo = ((csa_base + sizeof(csa_t)) >> 6 ) & 0xffff; /* get csa index */
  
  

  csa_size -= 1;                /* CSA's to initialise -= 1 */

  while (csa_size--)
  {
    pcxi.bits.pcxo = (current_csa >> 6) & 0xffff;
    pcsa->reg[0] = pcxi.reg;
    pcsa++;
    current_csa += sizeof(csa_t);
    
    if(reservedCSAs == 0)
    {
      if(LCXIsSet == 0)
      {
        _mtcr(CPU_LCX, pcxi.reg);         /* initialise LCX with reserved CSAs*/
        LCXIsSet = 1;
      }
    }else
    {
      reservedCSAs--;
    }
  }
  pcxi.bits.pcxo = (current_csa >> 6) & 0xffff;
  _mtcr(CPU_FCX, pcxi.reg);         /* initialise FCX */
}

void Start_Core(unsigned int coreId)
{
  if (coreId == 1)
  {
    /* enable CPU1 */
    CPU1_PC.U = (unsigned int)_start;   /* set start address */
    CPU1_DBGSR.U = 0x4;           /* reset HALT state */
  }
  else if (coreId == 2)
  {
    /* enable CPU2 */
    CPU2_PC.U = (unsigned int)_start;   /* set start address */
    CPU2_DBGSR.U = 0x4;           /* reset HALT state */
  }
}

static void system_set_pll(const TPllInitValue* pPllInitValue)
{
	WDT_ClearEndinit(&SCU_WDTSCON0.U);

	pSCU->OSCCON.U = pPllInitValue->uiOSCCON;

	while (pSCU->CCUCON1.B.LCK)
		;
	pSCU->CCUCON1.U = pPllInitValue->uiCCUCON1 | (1 << IFX_SCU_CCUCON1_UP_OFF);
	while (pSCU->CCUCON1.B.LCK)
		;
	pSCU->CCUCON1.U = pPllInitValue->uiCCUCON1;

	while (pSCU->CCUCON2.B.LCK)
		;
	pSCU->CCUCON2.U = pPllInitValue->uiCCUCON2 | (1 << IFX_SCU_CCUCON2_UP_OFF);
	while (pSCU->CCUCON2.B.LCK)
		;
	pSCU->CCUCON2.U = pPllInitValue->uiCCUCON2;

	pSCU->PLLCON0.U |= ((1 << IFX_SCU_PLLCON0_VCOBYP_OFF) | (1 << IFX_SCU_PLLCON0_SETFINDIS_OFF));
	pSCU->PLLCON1.U =  pPllInitValue->uiPLLCON1;				/* set K1,K2 divider */
	pSCU->PLLCON0.U =  pPllInitValue->uiPLLCON0					/* set P,N divider */
					| ((1 << IFX_SCU_PLLCON0_VCOBYP_OFF) | (1 << IFX_SCU_PLLCON0_CLRFINDIS_OFF));
	while (pSCU->CCUCON0.B.LCK)
		;
	pSCU->CCUCON0.U =  pPllInitValue->uiCCUCON0 | (1 << IFX_SCU_CCUCON0_UP_OFF);
	while (pSCU->CCUCON0.B.LCK)
		;
	pSCU->CCUCON0.U =  pPllInitValue->uiCCUCON0;
	WDT_SetEndinit(&SCU_WDTSCON0.U);

	if (0 == (pPllInitValue->uiPLLCON0 & (1 << IFX_SCU_PLLCON0_VCOBYP_OFF)))	/* no prescaler mode requested */
	{
#ifndef SYSTEM_PLL_HAS_NO_LOCK
		/* wait for PLL locked */
		while (0 == pSCU->PLLSTAT.B.VCOLOCK)
			;
#endif

		WDT_ClearEndinit(&SCU_WDTSCON0.U);
		pSCU->PLLCON0.B.VCOBYP = 0;			/* disable VCO bypass */
		WDT_SetEndinit(&SCU_WDTSCON0.U);
	}
}

#pragma section

