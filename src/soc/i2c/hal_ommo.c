
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
void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
#if SYS_DEBUG_I2C
	printf("OMMO HAL I2C Transfer CS:%d,Length:%d/r/n",address,length);
#endif

#if SYS_MOCK_I2C
#include <string.h>
	static uint8_t i2c_rx_data[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if(rx_data!=0x0L)
		memcpy(rx_data,i2c_rx_data,16);
#endif
}
/*------------------------------------*/

/*================================================================*/
/* end of hal_ommo.c */
