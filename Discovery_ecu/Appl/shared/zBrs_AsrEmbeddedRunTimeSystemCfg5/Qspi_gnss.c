#include "Qspi_gnss.h"

uint8 RTK_write_but[4] = {0x12, 0x34, 0x56, 0x78};
uint8 RTK_read_but[4] = {0};

uint8 RTK_test_write_buf[1] = {0xFF};
uint8 RTK_test_read_but[1] = {0xab};
uint8 GNSS_start_buf[] = {0xF1, 0xD9, 0x06, 0x40, 0x01, 0x00, 0x11, 0x58, 0x32, 0xFF, 0xFF, 0xFF};
uint8 GNSS_GPS_MODE = {0xF1, 0xD9, 0x06, 0x0C, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x17, 0xA0};

uint8 GNSS_NMEA301[] = {0xF1, 0xD9, 0x06, 0x43, 0x01, 0x00, 0x01, 0x4B, 0x2E, 0xFF, 0xFF, 0xFF};
uint8 GNSS_OPEN_GGA[] = {0xF1, 0xD9, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x01, 0xFB, 0x10, 0xFF};

#define MAX_RECEUVE_NUM 80
uint8 GNSS_receive_buf[MAX_RECEUVE_NUM] = {0};


void Qspi_gnss_test(boolean IsInit)
{
    if(IsInit == TRUE)
    {
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, GNSS_start_buf, NULL_PTR, sizeof(GNSS_start_buf));
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequenceRTK);
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, GNSS_NMEA301, NULL_PTR, sizeof(GNSS_NMEA301));
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequenceRTK);
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, GNSS_OPEN_GGA, NULL_PTR, sizeof(GNSS_OPEN_GGA));
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequenceRTK);
    }
    else
    {
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, RTK_test_write_buf, RTK_test_read_but, sizeof(RTK_test_write_buf));
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequenceRTK);
    }
}
