
/*------------------------------------
 * hal.c
 * Create:  2025-06-28
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"
/*================================================================*/
#include "0ctr.h"
#if SYS_DEBUG_SPI
#define spi_print(x...)	printf(x);
#else
#define spi_print(x...)
#endif
/*------------------------------------*/
#define SPI_MAX_PACKET_LEN	256
static uint8_t spi_tx_data[SPI_MAX_PACKET_LEN];
static uint8_t spi_tx_len;

static uint8_t spi_cmd_data[SPI_MAX_PACKET_LEN];
static uint8_t spi_cmd_len;
static uint8_t spi_rx_data[SPI_MAX_PACKET_LEN];
static uint8_t spi_rx_len;
/*------------------------------------*/
void hal_dma_init_spi_bus(void);
void hal_dma_init_spi_bus()
{
	spi_tx_len = 0;
	spi_rx_len = 0;
	spi_tx_data[0] = '\0';
	spi_rx_data[0] = '\0';
}
/*------------------------------------*/
#include <string.h>
bool hal_dma_start_tx_spi_device(uint8_t *tx_data, uint8_t tx_len);
bool hal_dma_start_tx_spi_device(uint8_t *tx_data, uint8_t tx_len)
{
	memcpy(spi_tx_data,tx_data,tx_len);
	spi_tx_len = tx_len;
	spi_print("SPI start send %d bytes to device\r\n",tx_len);
	return true;	//success
}
bool hal_dma_finish_tx_spi_device(void);
bool hal_dma_finish_tx_spi_device()
{
	spi_print("SPI finish send %d bytes to device\r\n",spi_tx_len);
	void rbl_log_hex(unsigned char *data, int size);
	rbl_log_hex(spi_tx_data, spi_tx_len);
	spi_tx_len = 0;
	return true;	//success
}
/*------------------------------------*/
bool hal_dma_start_rx_spi_device(uint8_t *cmd_data,uint8_t *rx_data, uint8_t cmd_len);
bool hal_dma_start_rx_spi_device(uint8_t *cmd_data,uint8_t *rx_data, uint8_t cmd_len)
{
	spi_cmd_len = cmd_len;
	memcpy(spi_cmd_data,cmd_data,cmd_len);
	spi_rx_len = 0;
	spi_print("SPI start to read %d bytes from device\r\n",cmd_len);
	return true;	//success
}

bool hal_dma_finish_rx_spi_device(void);
bool hal_dma_finish_rx_spi_device()
{
#if	SYS_MOCK_SPI
	static char *rx_msg[4]={
			"MMC5983 SPI Sensor Data",
			"Null",
			"LSM6DSM SPI Sensor Data",
			"Null"
	};
	extern uint8_t bsp_current_cs;
#include <string.h>
	spi_rx_len = strlen(rx_msg[bsp_current_cs]);
	strcpy((char *)spi_rx_data,rx_msg[bsp_current_cs]);

	extern int spi_isr_enable;
	spi_isr_enable = 1;
#endif
	spi_print("SPI finish to read %d bytes from devicex\r\n",spi_rx_len);
	return true;	//success
}

bool hal_dma_read_rx_spi_device(uint8_t *rx_data, uint8_t *rx_len);
bool hal_dma_read_rx_spi_device(uint8_t *rx_data, uint8_t *rx_len)
{
	*rx_len = spi_rx_len;
	if(spi_rx_len == 0)
		return false;	 //no data
	spi_print("Application read %d bytes from SPI device\r\n",spi_rx_len);
	if(rx_data != 0x0L)
		memcpy(rx_data,spi_rx_data,spi_rx_len);
	//rx_data == 0x0L, only query
	return true;	//success
}
/*------------------------------------*/
void reg_dma_deinit_spi_bus(void);
void reg_dma_deinit_spi_bus()
{
}

/*================================================================*/
/* end of hal.c */
