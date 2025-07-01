
/*------------------------------------
 * task.c
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
#include "tos.h"
/*------------------------------------*/
#include "configuration.h"
extern void bsp_i2c_loop_thread(void);
extern void bsp_spi_loop_thread(void);
extern uint8_t bsp_get_cs(void);
extern void bsp_inc_cs(void);
void bsp_loop_thread(void);
void bsp_loop_thread()
{
	int port;
	int pno;
	uint8_t cs;
	cs = bsp_get_cs();
	for(port=0;port<BSP_MAX_SENSOR_PORT;port++)
	{
		if(bsp_sensor_config_table[port].configured == false)
			continue;
		pno = BSP_SSR_START_PNO+port;
		tos_set_pno(pno);
		if(bsp_sensor_config_table[port].con_type == BSP_I2C_SENSOR)
			bsp_i2c_loop_thread();
		else
		{
			if(bsp_sensor_config_table[port].addr_or_cs == cs)
				bsp_spi_loop_thread();	//SPI only permit one sensor work at same time
		}
	}
	bsp_inc_cs();
}
/*================================================================*/
/* end of task.c */
