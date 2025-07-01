
/*------------------------------------
 * reg.h
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
#ifndef SOC_I2C_REG_H_
#define SOC_I2C_REG_H_
/*================================================================*/
extern void reg_init_i2c_bus(void);
extern bool reg_write_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
extern bool reg_read_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length);
extern void reg_deinit_i2c_bus(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
/*================================================================*/
#endif
/* end of reg.h */
