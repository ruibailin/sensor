
/*------------------------------------
 * hal.c
 * Create:  2025-06-28
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * Support 3 types of hal functions
 * 1. pooling
 * 2. interrupt BYTE
 * 3. interrupt DMA
 * We suppose DMA is used for simple demo
 *
 *
 *------------------------------------
 */

#include "1imp.h"
/*================================================================*/
#include "0ctr.h"
#if SYS_DEBUG_I2C
#define i2c_print(x...)	printf(x)
#else
#define i2c_print(x...)
#endif
/*------------------------------------*/
#define I2C_MAX_PACKET_LEN	256
static uint8_t i2c_tx_data[I2C_MAX_PACKET_LEN];
static uint8_t i2c_tx_len;
static uint8_t i2c_tx_addr;

static uint8_t i2c_cmd_data[I2C_MAX_PACKET_LEN];
static uint8_t i2c_cmd_len;
static uint8_t i2c_rx_data[I2C_MAX_PACKET_LEN];
static uint8_t i2c_rx_len;
static uint8_t i2c_rx_addr;
/*------------------------------------*/
void hal_dma_init_i2c_bus(void);
void hal_dma_init_i2c_bus()
{
	i2c_tx_len = 0;
	i2c_rx_len = 0;
	i2c_tx_data[0] = '\0';
	i2c_rx_data[0] = '\0';
}
/*------------------------------------*/
#include <string.h>
bool hal_dma_start_tx_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_len);
bool hal_dma_start_tx_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_len)
{
	i2c_tx_addr = address;
	memcpy(i2c_tx_data,tx_data,tx_len);
	i2c_tx_len = tx_len;
	i2c_print("I2C start send %d bytes to device %02x\r\n",tx_len,address);
	return true;	//success
}
bool hal_dma_finish_tx_i2c_device(void);
bool hal_dma_finish_tx_i2c_device()
{
	i2c_print("I2C finish send %d bytes to device %02x\r\n",i2c_tx_len,i2c_tx_addr);
	i2c_tx_len = 0;
	return true;	//success
}
/*------------------------------------*/
bool hal_dma_start_rx_i2c_device(uint8_t address, uint8_t *cmd_data,uint8_t *rx_data, uint8_t cmd_len);
bool hal_dma_start_rx_i2c_device(uint8_t address, uint8_t *cmd_data,uint8_t *rx_data, uint8_t cmd_len)
{
	i2c_cmd_len = cmd_len;
	memcpy(i2c_cmd_data,cmd_data,cmd_len);
	i2c_rx_addr = address;
	i2c_rx_len = 0;
	i2c_print("I2C start to read from device %02x by command %d\r\n",address,cmd_len);
	return true;	//success
}

bool hal_dma_finish_rx_i2c_device(void);
bool hal_dma_finish_rx_i2c_device()
{
#if	SYS_MOCK_I2C
	static char rx_msg[]="MMC5603 I2C Sensor Data";
#include <string.h>
	i2c_rx_len = strlen(rx_msg);
	strcpy((char *)i2c_rx_data,rx_msg);

	extern int i2c_isr_enable;
	i2c_isr_enable = 1;
#endif
	i2c_print("I2C finish to read %d bytes from device %02x\r\n",i2c_rx_len,i2c_rx_addr);
	return true;	//success
}

bool hal_dma_read_rx_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_len);
bool hal_dma_read_rx_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_len)
{
	*rx_len = i2c_rx_len;
	if(i2c_rx_len == 0)
		return false;	 //no data
	i2c_print("Application read %d bytes from device %02x\r\n",i2c_rx_len,i2c_rx_addr);
	if(rx_data != 0x0L)
		memcpy(rx_data,i2c_rx_data,i2c_rx_len);
	//rx_data == 0x0L, only query
	return true;	//success
}
/*------------------------------------*/
void reg_dma_deinit_i2c_bus(void);
void reg_dma_deinit_i2c_bus()
{
}
/*================================================================*/
/* end of hal.c */
