
/*------------------------------------
 * reg.c
 * Create:  2025-06-28
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * register level i2c functions are very complicated
 * This is just for device control mode
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
}I2C_Register_t;
static I2C_Register_t reg_i2c_addr[SOC_MAX_I2C_NUM];
/*------------------------------------*/
void reg_init_i2c_bus(void);
void reg_init_i2c_bus()
{
	reg_i2c_addr[0].flag = 0;
}
bool reg_write_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
bool reg_write_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length)
{
	return true;	//success
}
bool reg_read_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length);
bool reg_read_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length)
{
	return true;	//success
}

void reg_deinit_i2c_bus(void);
void reg_deinit_i2c_bus()
{
}
/*================================================================*/
/* end of reg.c */
