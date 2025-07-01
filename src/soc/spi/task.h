
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


#ifndef SOC_SPI_TASK_H_
#define SOC_SPI_TASK_H_
/*================================================================*/
#include <stdint.h>
#include <stdbool.h>
extern bool soc_spi_is_tx_idle(void);
extern void soc_spi_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len);
/*------------------------------------*/
extern void soc_spi_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len);
extern bool soc_spi_is_rx_full(void);
extern uint8_t soc_spi_copy_rx_data(uint8_t *rx_data);
/*------------------------------------*/
extern void soc_spi_int_thread();
extern void soc_spi_loop_thread();
/*================================================================*/
#endif
/* end of task.h */
