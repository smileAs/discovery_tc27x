#include "Qspi_tlf35584.h"

#define TLF_BUFFER_SIZE 1
boolean TLF_A_Step;


typedef struct _AppQspi_TLF_Buffer
{
    uint16 spiTxBuffer[TLF_BUFFER_SIZE];                               /**< \brief Qspi Transmit buffer */
    uint16 spiRxBuffer[TLF_BUFFER_SIZE];                               /**< \brief Qspi receive buffer */
} AppQspi_TLF_Buffer;

AppQspi_TLF_Buffer Tlf_Buffer;

uint16 IfxTLF35584_read_write(uint16 send_data)
{
    Tlf_Buffer.spiTxBuffer[0] = send_data;
    while(Spi_GetSequenceResult(SpiConf_SpiChannel_SpiChannel_0) == SPI_SEQ_PENDING){};
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_0, Tlf_Buffer.spiTxBuffer, Tlf_Buffer.spiRxBuffer, 1);
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequencePMIC);
    /* we wait until our values are read from Qspi */
    while(Spi_GetSequenceResult(SpiConf_SpiChannel_SpiChannel_0) == SPI_SEQ_PENDING){};
    return (Tlf_Buffer.spiRxBuffer[0]);
}
void IfxTLF35584_init(void)
{
    /* first we check for A or B-step of TLF */
    /* we read the value from address 0x34 but ignore the returned value */
    IfxTLF35584_read_write(0x6801);  /* read address 0x34 */
    /* no we read the SPI status flags */
    if ((IfxTLF35584_read_write(0x3E01)>>1) & 0x4)
    {
        /* there was an address error, this is not the A-step */
        /* we reset the ADDRE flag */
        IfxTLF35584_read_write(0xBE09);  /* SPISF = 0x04 */
        TLF_A_Step = FALSE;
    }
    else
    {
        TLF_A_Step = TRUE;
    }
}

void IfxTLF35584_unprotect_register(void)
{
    IfxTLF35584_read_write(0x8756);  /* PROTCFG = 0xAB */
    IfxTLF35584_read_write(0x87DE);  /* PROTCFG = 0xEF */
    IfxTLF35584_read_write(0x86AD);  /* PROTCFG = 0x56 */
    IfxTLF35584_read_write(0x8625);  /* PROTCFG = 0x12 */
}

void IfxTLF35584_protect_register(void)
{
    IfxTLF35584_read_write(0x87BE);  /* PROTCFG = 0xDF */
    IfxTLF35584_read_write(0x8668);  /* PROTCFG = 0x34 */
    IfxTLF35584_read_write(0x877D);  /* PROTCFG = 0xBE */
    IfxTLF35584_read_write(0x8795);  /* PROTCFG = 0xCA */
}

void IfxTLF35584_disable_window_watchdog(void)
{
    uint16 uiWdcfg0;
    /* first we get the value of WDCFG0 to check the window watchdog */
    if (TLF_A_Step == TRUE)
        uiWdcfg0 = IfxTLF35584_read_write(0x0C00);  /* read WDCFG0 (0x06) */
    else
        uiWdcfg0 = IfxTLF35584_read_write(0x1A00);  /* read RWDCFG0 (0x0D) */
    /* if the WWDEN is cleared then return because the window watchdog is already disabled */
    if (!(uiWdcfg0 & 0x0010)) return;
    /* clear the WWDEN bit */
    uiWdcfg0 &= ~0x0010;
    /* correct the parity */
    if (uiWdcfg0 & 0x0001)
        uiWdcfg0 &= ~0x0001;
    else
        uiWdcfg0 |= 0x0001;
    /* set the write address to 0x06 */
    uiWdcfg0 |= (0x06<<9);
    /* Write back and disable the Window Watchdog */
    IfxTLF35584_read_write(uiWdcfg0);
}

void IfxTLF35584_enable_window_watchdog(void)
{
    uint16 uiWdcfg0;
    /* first we get the value of WDCFG0 to check the window watchdog */
    if (TLF_A_Step == TRUE)
        uiWdcfg0 = IfxTLF35584_read_write(0x0C00);  /* read WDCFG0 (0x06) */
    else
        uiWdcfg0 = IfxTLF35584_read_write(0x1A00);  /* read RWDCFG0 (0x0D) */
    /* if the WWDEN is set then return because the window watchdog is already enabled */
    if (uiWdcfg0 & 0x0010) return;
    /* set the WWDEN bit */
    uiWdcfg0 |= 0x0010;
    /* correct the parity */
    if (uiWdcfg0 & 0x0001)
        uiWdcfg0 &= ~0x0001;
    else
        uiWdcfg0 |= 0x0001;
    /* set the write address to 0x06 */
    uiWdcfg0 |= (0x06<<9);
    /* Write back and enable the Window Watchdog */
    IfxTLF35584_read_write(uiWdcfg0);
}


void IfxTLF35584_disable_err_pin_monitor(void)
{
    uint16 uiSyspcfg;
    if (TLF_A_Step == TRUE)
    {
        /* first we get the value of SYSPCFG0 to check the error pin monitor */
        uiSyspcfg = IfxTLF35584_read_write(0x0801);  /* read SYSPCFG0 (0x04) */
        /* if the ERREN is cleared then return because the error pin monitor is already disabled */
        if (!(uiSyspcfg & 0x0004)) return;
        /* clear the ERREN bit */
        uiSyspcfg &= ~0x0004;
        /* set the write address to 0x04 */
        uiSyspcfg |= (0x04<<9);
        /* parity must not be corrected */
    }
    else
    {
        /* first we get the value of RSYSPCFG1 to check the error pin monitor */
        uiSyspcfg = IfxTLF35584_read_write(0x1800);  /* read RSYSPCFG1 (0x0C) */
        /* if the ERREN is cleared then return because the error pin monitor is already disabled */
        if (!(uiSyspcfg & 0x0010)) return;
        /* clear the ERREN bit */
        uiSyspcfg &= ~0x0010;
        /* set the write address to 0x05 */
        uiSyspcfg |= (0x05<<9);
        /* correct the parity */
        if (uiSyspcfg & 0x0001)
            uiSyspcfg &= ~0x0001;
        else
            uiSyspcfg |= 0x0001;
    }
    /* Write back and disable the error pin monitor */
    IfxTLF35584_read_write(uiSyspcfg);
}

void IfxTLF35584_enable_err_pin_monitor(void)
{
    uint16 uiSyspcfg;
    if (TLF_A_Step == TRUE)
    {
        /* first we get the value of SYSPCFG0 to check the error pin monitor */
        uiSyspcfg = IfxTLF35584_read_write(0x0801);  /* read SYSPCFG0 (0x04) */
        /* if the ERREN is set then return because the error pin monitor is already enabled */
        if (!(uiSyspcfg & 0x0004)) return;
        /* set the ERREN bit */
        uiSyspcfg |= 0x0004;
        /* set the write address to 0x04 */
        uiSyspcfg |= (0x04<<9);
        /* parity must not be corrected */
    }
    else
    {
        /* first we get the value of SYSPCFG1 to check the error pin monitor */
        uiSyspcfg = IfxTLF35584_read_write(0x1800);  /* read SYSPCFG1 (0x0C) */
        /* if the ERREN is set then return because the error pin monitor is already enabled */
        if (!(uiSyspcfg & 0x0010)) return;
        /* set the ERREN bit */
        uiSyspcfg |= 0x0010;
        /* set the write address to 0x05 */
        uiSyspcfg |= (0x05<<9);
        /* correct the parity */
        if (uiSyspcfg & 0x0001)
            uiSyspcfg &= ~0x0001;
        else
            uiSyspcfg |= 0x0001;
    }
    /* Write back and enable the error pin monitor */
    IfxTLF35584_read_write(uiSyspcfg);
}

void IfxTLF35584_goto_normal_state(void)
{
    /* Switch TLF to normal state */
    if (TLF_A_Step == TRUE)
    {
        IfxTLF35584_read_write(0x9DD5);  /* DEVCTRL = 0xEA */
    }
    else
    {
        IfxTLF35584_read_write(0xABD5);  /* DEVCTRL = 0xEA */
        IfxTLF35584_read_write(0xAC2B);  /* DEVCTRLN = ~0xEA */
    }
}

void IfxTLF35584_goto_standby_state(void)
{
    if (TLF_A_Step == TRUE)
    {
        IfxTLF35584_read_write(0x9DD9);  /* DEVCTRL = 0xEC */
    }
    else
    {
        IfxTLF35584_read_write(0xABD9);  /* DEVCTRL = 0xEC */
        IfxTLF35584_read_write(0xAC27);  /* DEVCTRLN = ~0xEC */
    }
}

void Tlf35584_init(void)
{
    /* TLF init */
    IfxTLF35584_init();
    /* Disable Window Watchdog and ERR pin */
    IfxTLF35584_unprotect_register();
    IfxTLF35584_disable_window_watchdog();
    IfxTLF35584_disable_err_pin_monitor();
    IfxTLF35584_protect_register();
    /* Switch TLF to normal state */
    IfxTLF35584_goto_normal_state();
}
