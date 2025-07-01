
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
static char tx_cmd[]="LSM6DSM SPI 3 Command Data";
/*------------------------------------*/
#include "..\..\msg_ring_buf.h"
#include "..\configuration.h"
void start_LSM6DSM_data_write(void);
void start_LSM6DSM_data_write()
{
	mrb_push_msg(bsp_sensor_config_table[0].tx_messege_buf,tx_cmd);
	printf("Start to Send LSM6DSM Write Command\r\n");
}
/*================================================================*/
/* end of write.c */
