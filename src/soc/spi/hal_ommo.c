
/*------------------------------------
 * hal_ommo.c
 * Create:  2025-06-30
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
#include "hal.h"
//remark: in current design, chip_select is managed by BSP level,SOC no need to worry about it.
void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
	 hal_dma_start_tx_spi_device(tx_data, length);
	 hal_dma_start_rx_spi_device(tx_data, rx_data, length);
	 hal_dma_finish_rx_spi_device();
}
/*------------------------------------*/

/*================================================================*/
/* end of hal_ommo.c */
