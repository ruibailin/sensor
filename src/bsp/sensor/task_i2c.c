
/*------------------------------------
 * task_i2c.c
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
#if OMMO_DEBUG_SENSOR
#define bsp_i2c_print(x...)	printf(x)
#else
#define bsp_i2c_print(x...)
#endif
/*------------------------------------*/
#include "configuration.h"
#include "description.h"
#include "tos.h"
#include "soc.h"
/*------------------------------------*/
void bsp_i2c_loop_thread(void);
void bsp_i2c_loop_thread()
{
	int state;
	state = tos_get_state();
	int addr;
	addr = bsp_sensor_config_table[0].addr_or_cs;
	switch(state)
	{
	case BSP_SSR_INIT:
	{
		extern void bsp_init_sensor_data(int addr);
		bsp_init_sensor_data(0);
		tos_set_timer(BSP_READ_SENSOR_INTERVAL);
		tos_set_state(BSP_SSR_ONLINE);
	}
		break;
	case BSP_SSR_ONLINE:
	{
		if(!tos_check_timer())
			break;
		void *cmd;
		cmd = mrb_pop_msg(bsp_sensor_config_table[0].tx_messege_buf);
		if(cmd != 0x0L)
		{
			tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
			soc_i2c_request_tx(bsp_sensor_config_table[0].addr_or_cs,cmd,16);
			tos_set_state(BSP_SSR_ONLINE_WRITE);
			bsp_i2c_print("I2C Sensor %d Start Write/r/n",addr);
		}
		else
		{
			extern void start_MMC5603_data_read(uint8_t *buffer);
			start_MMC5603_data_read(bsp_sensor_config_table[0].data_area);
			tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
			soc_i2c_request_rx(bsp_sensor_config_table[0].addr_or_cs,bsp_sensor_config_table[0].data_area,16);
			tos_set_state(BSP_SSR_ONLINE_READ);
			bsp_i2c_print("I2C Sensor %d Start Read/r/n",addr);
		}
	}
		break;
	case BSP_SSR_ONLINE_READ:
	{
		if(soc_i2c_is_rx_full())
		{
			soc_i2c_copy_rx_data(bsp_sensor_config_table[0].data_area);
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_i2c_print("I2C Sensor %d End Read/r/n",addr);
		}
		else
		{
			if(!tos_check_timer())
				break;
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_OFFLINE);
			bsp_i2c_print("I2C Sensor %d OFFLINE/r/n",addr);
			break;
		}
	}
		break;
	case BSP_SSR_ONLINE_WRITE:
	{
		if(soc_i2c_is_tx_idle())
		{	//Transmission finished
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_i2c_print("I2C Sensor %d End Write/r/n",addr);
		}
		else
		{
			if(!tos_check_timer())
				break;
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_OFFLINE);
			bsp_i2c_print("I2C Sensor %d OFFLINE/r/n",addr);
			break;
		}
	}
		break;
	case BSP_SSR_OFFLINE:
	{
		extern void start_MMC5603_data_read(uint8_t *buffer);
		start_MMC5603_data_read(bsp_sensor_config_table[0].data_area);
		tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
		soc_i2c_request_rx(bsp_sensor_config_table[0].addr_or_cs,bsp_sensor_config_table[0].data_area,16);
		tos_set_state(BSP_SSR_ONLINE_READ);
	}
		break;
	case BSP_SSR_OFFLINE_TEST:
	{
		if(soc_i2c_is_rx_full())
		{
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_i2c_print("I2C Sensor %d ONLINE again/r/n",addr);
		}
		else
		{
			if(!tos_check_timer())
				break;
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_OFFLINE);
			break;
		}
	}
		break;
	default:
		break;
	}

}
/*================================================================*/
/* end of task_i2c.c */
