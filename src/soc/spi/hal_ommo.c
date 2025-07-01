
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
#include "0ctr.h"
//remark: in current design, chip_select is managed by BSP level,SOC no need to worry about it.
void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
#if SYS_DEBUG_SPI
	printf("OMMO HAL SPI Transfer CS:%d,Length:%d/r/n",chip_select,length);
#endif

#if SYS_MOCK_SPI
#include <string.h>
	extern int spi_isr_enable;
	spi_isr_enable = 1;
	static uint8_t spi_rx_data[16]={1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if(rx_data!=0x0L)
		memcpy(rx_data,spi_rx_data,16);
#endif
}
/*------------------------------------*/

/*================================================================*/
/* end of hal_ommo.c */
