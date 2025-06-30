
/*------------------------------------
 * hal.h
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
#ifndef SOC_I2C_HAL_H_
#define SOC_I2C_HAL_H_
/*================================================================*/
extern void hal_dma_init_i2c_bus(void);
extern bool hal_dma_start_tx_i2c_device(uint8_t address, uint8_t *tx_data, uint8_t tx_len);
extern bool hal_dma_finish_tx_i2c_device(void);
extern bool hal_dma_start_rx_i2c_device(uint8_t address, uint8_t *cmd_data, uint8_t cmd_len);
extern bool hal_dma_finish_rx_i2c_device(void);
extern bool hal_dma_read_rx_i2c_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_len);
extern void reg_dma_deinit_i2c_bus(void);
/*================================================================*/
#endif
/* end of hal.h */
