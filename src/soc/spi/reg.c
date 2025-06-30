
/*------------------------------------
 * reg.c
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
typedef struct
{
	//example,please refer to SOC manual
	uint8_t *tx_data;
	uint8_t *rx_data;
	uint8_t tx_length;
	uint8_t rx_length;
	uint8_t address;
	uint8_t flag;
}SPI_Register_t;
static SPI_Register_t *reg_spi_addr[SOC_MAX_SPI_NUM];
/*------------------------------------*/
void reg_init_spi_bus(void);
void reg_init_spi_bus()
{
	reg_spi_addr[0]->flag = 0;
}
bool reg_write_spi_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
bool reg_write_spi_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length)
{
	return true;	//success
}
bool reg_read_spi_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length);
bool reg_read_spi_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length)
{
	return true;	//success
}

void reg_deinit_spi_bus(void);
void reg_deinit_spi_bus()
{
	reg_spi_addr[0]->flag = 0;
}
/*================================================================*/
/* end of reg.c */
