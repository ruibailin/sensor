
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
#ifndef SOC_SPI_HAL_H_
#define SOC_SPI_HAL_H_
/*================================================================*/
extern void hal_dma_init_spi_bus(void);
extern bool hal_dma_start_tx_spi_device(uint8_t *tx_data, uint8_t tx_len);
extern bool hal_dma_finish_tx_spi_device(void);
extern bool hal_dma_start_rx_spi_device(uint8_t *cmd_data, uint8_t cmd_len);
extern bool hal_dma_finish_rx_spi_device(void);
extern bool hal_dma_read_rx_spi_device(uint8_t *rx_data, uint8_t *rx_len);
extern void reg_dma_deinit_spi_bus(void);
/*================================================================*/
#endif
/* end of hal.h */
