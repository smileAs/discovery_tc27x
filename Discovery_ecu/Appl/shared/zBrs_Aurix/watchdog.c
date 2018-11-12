/**
 * \file
 * \brief Watchdog Driver
 *
 * Watchdog Driver
 */
#include "BrsHw.h"
#include "watchdog.h"

#if defined (BRS_COMP_GNU)
# if defined(BRS_DERIVATIVE_TC21X)
  #include <TC21xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC22X)
  #include <TC22xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC23X)
  #include <TC23xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC26X)
  #include <TC26xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC27X)
  #include <TC27xc/Ifx_reg.h> //vademi change from c to a
# elif defined (BRS_DERIVATIVE_TC29X)
  #include <TC29xa/Ifx_reg.h>
# else 
  #error "No rule for the register definitions of your derivative implemented yet"
# endif
#endif /*BRS_COMP_GNU*/

sint32 wdt_default (void);
sint32 wdt_init (void);
sint32 wdt_setdisable (void);
sint32 wdt_setenable (void);
sint32 wdt_trigger (void);

#if defined (BRS_COMP_GNU)
  #pragma section ".cramtext" awx 4
#endif

/*!
 * \brief   Gets the Address of the Watchdog wdtcon0
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 * returns 0 in case of failure
 */
uint32 * getaddrwdtcon0 (sint32 nr)
{
  if (nr == 0)
    return ((uint32 *) & SCU_WDTCPU0CON0.U);
  if (nr == -1)
    return ((uint32 *) & SCU_WDTSCON0.U);
  if (nr == 1)
    return ((uint32 *) & SCU_WDTCPU1CON0.U);
  if (nr == 2)
    return ((uint32 *) & SCU_WDTCPU2CON0.U);
  return (0);
}

/*!
 * \brief   Gets the Address of the Watchdog wdtcon1
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 * Returnes value, which was configured.
 * returns 0 in case of failure
 */
uint32 * getaddrwdtcon1 (sint32 nr)
{
  if (nr == 0)
    return ((uint32 *) & SCU_WDTCPU0CON1.U);
  if (nr == -1)
    return ((uint32 *) & SCU_WDTSCON1.U);
  if (nr == 1)
    return ((uint32 *) & SCU_WDTCPU1CON1.U);
  if (nr == 2)
    return ((uint32 *) & SCU_WDTCPU2CON1.U);
  return (0);
}

/*!
 * \brief   Password and Modify access
 *
 * value + pointer to watchdog wdtcon0
 */
void SCU_vWriteWDTCON0 (uint32 uwValue, uint32 * pwdtcon0)
{
  uint32 uwDummy;
  uwDummy = *pwdtcon0;
  if (uwDummy & (1 << 1))
  {
    uwDummy &= 0xffffff00; /* see table 5-19 (Password Access Bit Pattern Requirements) */
    uwDummy |= 0xf1;
    /* Password ready. Store it to WDT_CON0 to unprotect the register. */
    *(volatile uint32 *) pwdtcon0 = uwDummy;    /* unlock access */
  }
  /* set wdtrel */
  uwDummy = (uwDummy & ~(0xffff << 16)) | (0 << 16);
  /* Set bit 1 (invert WDTLCK) */
  /* Set/Clear ENDINIT bit */
  if (uwValue & 0x1)
    uwDummy |= (1 << 1) | (1 << 0);
  else
    uwDummy = (uwDummy & ~(1 << 0)) | (1 << 1);
  /* Clear bits 3:2 */
  uwDummy &= ~(3 << 2);
  /* Set bits 7:4 */
  uwDummy |= (0xf << 4);
  *pwdtcon0 = uwDummy | (uwValue & 0xFFFFFF00);
  /*uwDummy = *(volatile uint32 *) pwdtcon0; visbwa: removed useless assignment (would be removed by compiler anyway) */
} /* End of function MAIN_vWriteWDTCON0 */

/*!
 * \brief   Service Watchdog 
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 * Reload value and Password
 */
void SCU_vServiceWDT (sint32 nr, uint16 usReload, uint8 ubPassword)
{
  uint32 *pwdtcon0;
  pwdtcon0 = getaddrwdtcon0 (nr);
  SCU_vWriteWDTCON0 ((usReload << 16) + (ubPassword << 8) + 1, pwdtcon0); /* service WDT */
} /* End of function SCU_vServiceWDT */

/*!
 * \brief   Disable Watchdog
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 */
void SCU_vDisableWDT (sint32 nr)
{
  uint32 *pwdtcon1;
  pwdtcon1 = getaddrwdtcon1 (nr);
  SCU_vResetENDINIT (nr);
  *pwdtcon1 |= 0x0000008; /* disable watchdog */
  SCU_vSetENDINIT (nr);
}

/*!
 * \brief   Refresh after Fail
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 */
void SCU_vWatchdogFailRefresh (sint32 nr)
{
  uint32 *pwdtcon1;
  pwdtcon1 = getaddrwdtcon1 (nr);
  SCU_vResetENDINIT (nr);
  *pwdtcon1 |= 0x00000001; /* disable watchdog */
  SCU_vSetENDINIT (nr);
}

/*!
 * \brief   Enable Watchdog
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 */
void SCU_vEnableWDT (sint32 nr)
{
  uint32 *pwdtcon1;
  pwdtcon1 = getaddrwdtcon1 (nr);
  SCU_vResetENDINIT (nr);
  *pwdtcon1 &= ~0x00000008; /* enable watchdog */
  SCU_vSetENDINIT (nr);
}

/*!
 * \brief   SetEndInit
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 */
void SCU_vSetENDINIT (sint32 nr)
{
  uint32 *pwdtcon0;
  pwdtcon0 = getaddrwdtcon0 (nr);
  SCU_vWriteWDTCON0 (*pwdtcon0 | 0x00000001, pwdtcon0);
}

/*!
 * \brief   ClearEndinit
 *
 * -1 Safety Watchdog, 0 CPU0, 1 CPU1, 2 CPU2
 */
void SCU_vResetENDINIT (sint32 nr)
{
  uint32 *pwdtcon0;
  pwdtcon0 = getaddrwdtcon0 (nr);
  SCU_vWriteWDTCON0 (*pwdtcon0 & ~0x00000001, pwdtcon0);
}

#if defined (BRS_COMP_GNU)
  #pragma section
#else
#error "Your Compiler is not yet verified here."
#endif

/*!
 * \brief   Disable the watchdog CPU0
 *
 * ...
 */
sint32 wdt_setdisable (void)
{
  SCU_vDisableWDT (0);
  return (0);
}

/*!
 * \brief   Enable the watchdog CPU0
 *
 * ...
 */
sint32 wdt_setenable (void)
{
  SCU_vEnableWDT (0);
  return (0);
}

/*!
 * \brief   Trigger the watchdog CPU0, Service
 *
 * ...
 */
sint32 wdt_trigger (void)
{
  SCU_vServiceWDT (0, 0x2000, 0x0000);
  return (0);
}
