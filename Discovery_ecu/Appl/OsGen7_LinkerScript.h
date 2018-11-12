/*
 * tricoreIROM.x -- TriBoard-TC27xx/AppKit-TC27xx full linker script
 *   (using internal Flash for code and internal RAM for data)
 *
 * Copyright (C) 1982-2014 HighTec EDV-Systeme GmbH.
 */

/* do not replace tricore in the OUTPUT_ARCH below */
#undef tricore


OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)
ENTRY(_START)

#ifndef ConfigSC1NonAsrMaster
# define CORE0_IS_ASR
# define CORE1_IS_ASR
# define CORE2_IS_ASR
#endif
#if defined(Config1) || defined(Config1Async) || defined(Config3) || defined(Config3Pid) || defined(MinConfig)
# define CORE1_IS_ASR
#endif
#if defined(Config1) || defined(MinConfig)
# define CORE2_IS_ASR
#endif


#define OS_LINK_GAP_BETWEEN_MPU_REGIONS 16

__TRICORE_DERIVATE_MEMORY_MAP__ = 0x2700;
_start_tc1 = _START;
_start_tc2 = _START;
/* the symbol __TRICORE_DERIVATE_NAME__ will be defined in the crt0_tc27x.c and is
 * tested here to confirm that this memory map and the startup file will fit together
 */
_. = ASSERT ((__TRICORE_DERIVATE_MEMORY_MAP__ == __TRICORE_DERIVATE_NAME__), "Using wrong Memory Map. This Map is for TC29XX");

/* minimal heap size (C library stuff) */
__HEAP_SIZE = DEFINED (__HEAP_SIZE) ? __HEAP_SIZE : 16K;

MEMORY
{
/* internal flash memories */
  int_flash0 (rx): org = 0x80000000, len = 1M
  int_flash0_trap (rx): org = 0x80100000, len = 512K
  int_flash0_int (rx): org = 0x80110000, len = 512K
  int_flash1 (rx): org = 0x80200000, len = 2M

/* ED (emulation device) memory */
  ed_mem (rx):  org = 0x9f000000, len = 1M

/* internal code ram */
  int_psprcpu0 (rxc0): org = 0xc0000000, len = 24K
  int_psprcpu1 (rxc1): org = 0xc0000000, len = 24K
  int_psprcpu2 (rxc2): org = 0xc0000000, len = 24K

/* internal data ram */
  int_dsprcpu0 (wc0!x): org = 0xd0000000, len = 112K
  int_dsprcpu1 (wc1!x): org = 0xd0000000, len = 120K
  int_dsprcpu2 (wc2!x): org = 0xd0000000, len = 120K

/* global view on internal memories */
  glb_int_psprcpu0 (rx): org = 0x70100000, len = 24K
  glb_int_psprcpu1 (rx): org = 0x60100000, len = 24K
  glb_int_psprcpu2 (rx): org = 0x50100000, len = 24K
  glb_int_dsprcpu0 (w!x): org = 0x70000000, len = 112K
  glb_int_dsprcpu1 (w!x): org = 0x60000000, len = 120K
  glb_int_dsprcpu2 (w!x): org = 0x50000000, len = 120K

/* global LMU RAM */
/* using the non cachable address enable shared accesses */
  lmu_sram (wx): org = 0xB0000000, len = 32K

/* local view on GTM/MCS data and code memory */
  int_mcs0_code (rx): org = 0x0000, len = 4K
  int_mcs0_data (w):  org = 0x1000, len = 2K

/* TriCore view on GTM/MCS data and code memory */
  glb_mcs0_code (rx): org = 0xf0138000, len = 4K
  glb_mcs0_data (w):  org = 0xf0139000, len = 2K
}

/* map local memory address to the corresponding global address */
REGION_MAP("CPU0", ORIGIN(int_dsprcpu0),  LENGTH(int_dsprcpu0),  ORIGIN(glb_int_dsprcpu0))
REGION_MAP("CPU1", ORIGIN(int_dsprcpu1),  LENGTH(int_dsprcpu1),  ORIGIN(glb_int_dsprcpu1))
REGION_MAP("CPU2", ORIGIN(int_dsprcpu2),  LENGTH(int_dsprcpu2),  ORIGIN(glb_int_dsprcpu2))
REGION_MAP("CPU0", ORIGIN(int_psprcpu0),  LENGTH(int_psprcpu0),  ORIGIN(glb_int_psprcpu0))
REGION_MAP("CPU1", ORIGIN(int_psprcpu1),  LENGTH(int_psprcpu1),  ORIGIN(glb_int_psprcpu1))
REGION_MAP("CPU2", ORIGIN(int_psprcpu2),  LENGTH(int_psprcpu2),  ORIGIN(glb_int_psprcpu2))

SECTIONS
{
  .startup_bmhd :
  {
    /* boot header */
    KEEP (*(.bmhd.STARTUP))
    . = ALIGN(8);
  } > int_flash0 =0x00

  .startup_code : FLAGS(axl)
  {
    . = ALIGN(4);
    KEEP (*(.text.STARTUP))
  } > int_flash0

  /*
   * Allocate trap and interrupt vector tables.
   */
  .trap_table  : FLAGS(axl)
  {
    . = ALIGN(32);
    __BTV_BASE_CORE0 = .;
	#if defined(CORE0_IS_ASR)
     #define OS_LINK_EXCVEC_CODE
	 #include "Os_Link_Core0.ld"
	#endif
    . = ALIGN(32);
    __BTV_BASE_CORE1 = .;
	#if defined(CORE1_IS_ASR)
     #define OS_LINK_EXCVEC_CODE
	 #include "Os_Link_Core1.ld"
	#endif
    . = ALIGN(32);
    __BTV_BASE_CORE2 = .;
	#if defined(CORE2_IS_ASR)
     #define OS_LINK_EXCVEC_CODE
	 #include "Os_Link_Core2.ld"
	#endif
  } > int_flash0_trap =0x00

  .interrupt_table : FLAGS(axl)
  {
    . = ALIGN(32);
    __BIV_BASE_CORE0 = .;
	#if defined(CORE0_IS_ASR)
     #define OS_LINK_INTVEC_CODE
	 #include "Os_Link_Core0.ld"
	#endif
    . = ALIGN(32);
    __BIV_BASE_CORE1 = .;
	#if defined(CORE1_IS_ASR)
     #define OS_LINK_INTVEC_CODE
	 #include "Os_Link_Core1.ld"
	#endif
    . = ALIGN(32);
    __BIV_BASE_CORE2 = .;
	#if defined(CORE2_IS_ASR)
     #define OS_LINK_INTVEC_CODE
	 #include "Os_Link_Core2.ld"
	#endif
  } > int_flash0_int =0x00

  .normal_code   : FLAGS(axl)
  {
    #if defined(CORE0_IS_ASR)
  	 #define OS_LINK_CALLOUT_CODE
      #include "Os_Link_Core0.ld"
    #endif
    
    #if defined(CORE1_IS_ASR)
  	 #define OS_LINK_CALLOUT_CODE
      #include "Os_Link_Core1.ld"
    #endif
    
    #if defined(CORE2_IS_ASR)
  	 #define OS_LINK_CALLOUT_CODE
      #include "Os_Link_Core2.ld"
    #endif
    
    #define OS_LINK_CODE
    #define OS_LINK_CALLOUT_CODE
     #include "Os_Link.ld"
  } > int_flash1

  .normal_constants   : FLAGS(arl)
  {
	  #if defined(CORE0_IS_ASR)
     #define OS_LINK_CONST
     #include "Os_Link_Core0.ld"
	 #endif
	 #if defined(CORE1_IS_ASR)
	 #define OS_LINK_CONST
     #include "Os_Link_Core1.ld"
	 #endif
	 #if defined(CORE2_IS_ASR)
	  #define OS_LINK_CONST
      #include "Os_Link_Core2.ld"
	 #endif
  } > int_flash1


#ifdef CORE0_IS_ASR
  .normal_bss_core0   : FLAGS(aw)
  {
    #define OS_LINK_KERNEL_STACKS
    #include "Os_Link_Core0_Stacks.ld"
    osEndOf_Core0Stack = .;

    /* OS_LINK_GAP_BETWEEN_MPU_REGIONS has already been added to . in the generated linker script */

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
    osBeginOf_Group_SystemApplication_OsCore0 = .;
    osBeginOf_Group_SystemApplication_OsCore0_All = .;
    #include "Os_Link_Core0.ld"
    osEndOf_Group_SystemApplication_OsCore0 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE0_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE0_NEAR
    osBeginOf_Group_SystemApplication_Trusted_OsCore0 = .;
    osBeginOf_Group_SystemApplication_Trusted_OsCore0_All = .;
    #include "Os_Link_Core0.ld"
    osEndOf_Group_SystemApplication_Trusted_OsCore0 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
    #define OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
    #include "Os_Link_Core0.ld"
	
  } > glb_int_dsprcpu0
  osEndOf_Core0StackInAlias = (osEndOf_Core0Stack & ~ 0xF0000000) | 0xD0000000;
#endif // CORE0_IS_ASR

#ifdef CORE1_IS_ASR
  .normal_bss_core1   : FLAGS(aw)
  {
    #define OS_LINK_KERNEL_STACKS
    #include "Os_Link_Core1_Stacks.ld"
    osEndOf_Core1Stack = .;

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE1_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE1_NEAR
    osBeginOf_Group_SystemApplication_OsCore1 = .;
    osBeginOf_Group_SystemApplication_OsCore1_All = .;
    #include "Os_Link_Core1.ld"
    osEndOf_Group_SystemApplication_OsCore1 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE1_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE1_NEAR
    osBeginOf_Group_SystemApplication_Trusted_OsCore1 = .;
    osBeginOf_Group_SystemApplication_Trusted_OsCore1_All = .;
    #include "Os_Link_Core1.ld"
    osEndOf_Group_SystemApplication_Trusted_OsCore1 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
    #define OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
    #include "Os_Link_Core1.ld"

  } > glb_int_dsprcpu1
  osEndOf_Core1StackInAlias = (osEndOf_Core1Stack & ~ 0xF0000000) | 0xD0000000;
#endif //CORE1_IS_ASR

#ifdef CORE2_IS_ASR
  .normal_bss_core2   : FLAGS(aw)
  {
    #define OS_LINK_KERNEL_STACKS
    #include "Os_Link_Core2_Stacks.ld"
    osEndOf_Core2Stack = .;

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE2_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE2_NEAR
    osBeginOf_Group_SystemApplication_OsCore2 = .;
    osBeginOf_Group_SystemApplication_OsCore2_All = .;
    #include "Os_Link_Core2.ld"
    osEndOf_Group_SystemApplication_OsCore2 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE2_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_TRUSTED_OSCORE2_NEAR
    osBeginOf_Group_SystemApplication_Trusted_OsCore2 = .;
    osBeginOf_Group_SystemApplication_Trusted_OsCore2_All = .;
    #include "Os_Link_Core2.ld"
    osEndOf_Group_SystemApplication_Trusted_OsCore2 = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    #define OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
    #define OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
    #include "Os_Link_Core2.ld"

  } > glb_int_dsprcpu2
  osEndOf_Core2StackInAlias = (osEndOf_Core2Stack & ~ 0xF0000000) | 0xD0000000;
#endif //CORE2_IS_ASR

  .normal_bss   : FLAGS(aw)
  {
    #define OS_LINK_VAR_KERNEL_FAR_NOINIT
    #define OS_LINK_VAR_KERNEL_NEAR_NOINIT
    #include "Os_Link.ld"


    osBeginOf_SharedData = .;
    #define OS_LINK_VAR_GLOBALSHARED_FAR_NOINIT
    #define OS_LINK_VAR_GLOBALSHARED_NEAR_NOINIT
    #include "Os_Link.ld"
    osEndOf_SharedData = . - OS_LINK_GAP_BETWEEN_MPU_REGIONS;

    /* Map EthDesc*/
  /*. = ALIGN(16);
	*(*.EthDesc) 
	. = ALIGN(16);
	. += 16;
   */
    /* Map EthRumBuf*/
 /*   . = ALIGN(16);
    *(*.EthBuffers)
    . = ALIGN(16);
    . += 16;
    */
    /**/ *(*.bss*)
  } > glb_int_dsprcpu0


  .initdata  :  FLAGS(awl)
  {
    *(*.data.a4)
    . = ALIGN(8);
    *(*.data.a2)
    . = ALIGN(8);
    *(*.data.a1)
    . = ALIGN(8);
	#define OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE0
	#include "Os_Link_Core0.ld"
  } > glb_int_dsprcpu0 AT> int_flash1


  /*
   * Define CSAs
   */
  .CPU0.csa : ALIGN(64) FLAGS(aw)
  {
    . = . + 0x14000;
    __CSA_BEGIN_CPU0_ = .;
    . +=  25600;
    __CSA_END_CPU0_ = .;
  } > int_dsprcpu0
  __CSA_SIZE_CPU0_ = __CSA_END_CPU0_ - __CSA_BEGIN_CPU0_;

  .CPU1.csa : ALIGN(64) FLAGS(aw)
  {
    . = . + 0x14000;
    __CSA_BEGIN_CPU1_ = .;
    . +=  8192;
    __CSA_END_CPU1_ = .;
  } > int_dsprcpu1
  __CSA_SIZE_CPU1_ = __CSA_END_CPU1_ - __CSA_BEGIN_CPU1_;

  .CPU2.csa : ALIGN(64) FLAGS(aw)
  {
    . = . + 0x14000;
    __CSA_BEGIN_CPU2_ = .;
    . +=  8192;
    __CSA_END_CPU2_ = .;
  } > int_dsprcpu2
  __CSA_SIZE_CPU2_ = __CSA_END_CPU2_ - __CSA_BEGIN_CPU2_;


  .clear_sec : ALIGN(8) FLAGS(arl)
  {
    PROVIDE(__clear_table = .);
    /*
    LONG(0 + ADDR(.zero_data_core0));          LONG(SIZEOF(.zero_data_core0));
    LONG(0 + ADDR(.zero_data_core1));          LONG(SIZEOF(.zero_data_core1));
    LONG(0 + ADDR(.zero_data_core2));          LONG(SIZEOF(.zero_data_core2));
    */
    LONG(-1);                                  LONG(-1);
  } > int_flash1
  .copy_sec  : ALIGN(8) FLAGS(arl)
  {
    PROVIDE(__copy_table = .);
    /*
    LONG(LOADADDR(.normal_data));         LONG(0 + ADDR(.normal_data));         LONG(SIZEOF(.normal_data));
    */
    LONG(LOADADDR(.initdata)); LONG(0 + ADDR(.initdata)); LONG(SIZEOF(.initdata));
    LONG(-1);                             LONG(-1);                             LONG(-1);
  } > int_flash1

}
