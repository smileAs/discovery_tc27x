#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_

extern uint32 * getaddrwdtcon0 (sint32 nr);
extern uint32 * getaddrwdtcon1 (sint32 nr);

extern void SCU_vWriteWDTCON0 (uint32 uwValue, uint32 * pwdtcon0);
extern void SCU_vServiceWDT (sint32 nr, uint16 usReload, uint8 ubPassword);
extern void SCU_vDisableWDT (sint32 nr);
extern void SCU_vWatchdogFailRefresh (sint32 nr);
extern void SCU_vEnableWDT (sint32 nr);
extern void SCU_vSetENDINIT (sint32 nr);
extern void SCU_vResetENDINIT (sint32 nr);
extern sint32 wdt_setdisable (void);
extern sint32 wdt_setenable (void);
extern sint32 wdt_trigger (void);

#endif /*_WATCHDOG_H_*/
