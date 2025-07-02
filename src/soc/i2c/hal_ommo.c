
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
void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
	 hal_dma_start_tx_i2c_device(address, tx_data, length);
	 hal_dma_start_rx_i2c_device(address, tx_data, rx_data, length);
	 extern int i2c_run_enable;
	 if(i2c_run_enable != 1)
		 return;	//no conncetion
	 hal_dma_finish_rx_i2c_device();
}
/*------------------------------------*/

/*================================================================*/
/* end of hal_ommo.c */
