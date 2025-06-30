
/*------------------------------------
 * task.h
 * Create:  2025-06-29
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
#ifndef SOC_I2C_TASK_H_
#define SOC_I2C_TASK_H_
/*================================================================*/
extern bool soc_i2c_is_tx_idle(void);
extern void soc_i2c_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len);
/*------------------------------------*/
extern void soc_i2c_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len);
extern bool soc_i2c_is_rx_full(void);
extern uint8_t soc_i2c_copy_rx_data(uint8_t *rx_data);
/*------------------------------------*/
extern void soc_i2c_int_thread();
extern void soc_i2c_loop_thread();
/*================================================================*/
#endif
/* end of task.h */
