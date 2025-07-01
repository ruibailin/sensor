
/*------------------------------------
 * write.c
 * Create:  2025-07-01
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */


/*================================================================*/
static char tx_cmd[]="MMC5983 SPI 1 Command Data";
/*------------------------------------*/
#include "..\..\msg_ring_buf.h"
#include "..\configuration.h"
void start_MMC5983_data_write(void);
void start_MMC5983_data_write()
{
	mrb_push_msg(bsp_sensor_config_table[1].tx_messege_buf,tx_cmd);
	printf("Start to Send MMC5983 Write Command\r\n");
}
/*================================================================*/
/* end of write.c */
