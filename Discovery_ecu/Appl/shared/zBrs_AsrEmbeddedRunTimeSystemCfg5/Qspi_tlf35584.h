#ifndef _TLF35584_H
#define _TLF35584_H
#include "Spi.h"
uint16 IfxTLF35584_read_write(uint16 send_data);
void IfxTLF35584_init(void);
void IfxTLF35584_unprotect_register(void);
void IfxTLF35584_protect_register(void);
void IfxTLF35584_disable_window_watchdog(void);
void IfxTLF35584_enable_window_watchdog(void);
void IfxTLF35584_disable_err_pin_monitor(void);
void IfxTLF35584_enable_err_pin_monitor(void);
void IfxTLF35584_goto_normal_state(void);
void IfxTLF35584_goto_standby_state(void);
void Tlf35584_init(void);
#endif
