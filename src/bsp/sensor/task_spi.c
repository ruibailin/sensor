
/*------------------------------------
 * task_spi.c
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
#if SYS_DEBUG_SENSOR
#define bsp_spi_print(x...)	printf(x)
#else
#define bsp_spi_print(x...)
#endif
/*------------------------------------*/
#include "configuration.h"
#include "description.h"
#include "tos.h"
#include "soc.h"
/*------------------------------------*/
void bsp_spi_loop_thread(void);
void bsp_spi_loop_thread()
{
	int state;
	state = tos_get_state();
	int port,cs;
	port = tos_get_pno()-BSP_SSR_START_PNO;
	cs = bsp_sensor_config_table[0].addr_or_cs;
	//according to define, port is chip select
	switch(state)
	{
	case BSP_SSR_INIT:
	{
		extern void bsp_init_sensor_data(int port);
		bsp_init_sensor_data(port);
		tos_set_timer(BSP_READ_SENSOR_INTERVAL);
		tos_set_state(BSP_SSR_ONLINE);
	}
		break;
	case BSP_SSR_ONLINE:
	{
		if(!tos_check_timer())
			break;
		void *cmd;
		cmd = mrb_pop_msg(bsp_sensor_config_table[port].tx_messege_buf);
		if(cmd != 0x0L)
		{
			tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
			soc_spi_request_tx(bsp_sensor_config_table[port].addr_or_cs,cmd,16);
			tos_set_state(BSP_SSR_ONLINE_WRITE);
			bsp_spi_print("SPI Sensor %d Start Write\r\n",port);
		}
		else
		{
			if(bsp_sensor_config_table[port].model_type == 5983)
			{
				extern void start_MMC5983_data_read(uint8_t chip_select,uint8_t *buffer);
				start_MMC5983_data_read(cs,bsp_sensor_config_table[port].data_area);
			}
			if(bsp_sensor_config_table[port].model_type == 6)
			{
				void start_LSM6DSM_data_read(uint8_t chip_select, uint8_t *buffer);
				start_LSM6DSM_data_read(cs,bsp_sensor_config_table[port].data_area);
			}

			tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
			soc_spi_request_rx(bsp_sensor_config_table[port].addr_or_cs,bsp_sensor_config_table[port].data_area,bsp_sensor_config_table[port].data_area,16);
			tos_set_state(BSP_SSR_ONLINE_READ);
			bsp_spi_print("SPI Sensor %d Start Read\r\n",port);
		}
	}
		break;
	case BSP_SSR_ONLINE_READ:
	{
		if(soc_spi_is_rx_full())
		{
			soc_spi_copy_rx_data(bsp_sensor_config_table[port].data_area);
			data_read_callback(port,bsp_sensor_config_table[port].data_area);
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_spi_print("SPI Sensor %d End Read\r\n",port);
#if SYS_WRITE_SENSOR
			if(port == 1)
			{
				printf("Test Sensor on port 1!\r\n");
				extern void start_MMC5983_data_write(void);
				start_MMC5983_data_write();
			}
			if(port == 3)
			{
				printf("Test Sensor on port 3!\r\n");
				extern void start_LSM6DSM_data_write(void);
				start_LSM6DSM_data_write();
			}
#endif
		}
		else
		{
			if(!tos_check_timer())
				break;
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_OFFLINE);
			bsp_spi_print("SPI Sensor %d OFFLINE\r\n",port);
			device_inserted_removed_callback(port,false);
			break;
		}
	}
		break;
	case BSP_SSR_ONLINE_WRITE:
	{
		if(soc_spi_is_tx_idle())
		{	//Transmission finished
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_spi_print("SPI Sensor %d End Write\r\n",port);
		}
		else
		{
			if(!tos_check_timer())
				break;
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_OFFLINE);
			bsp_spi_print("SPI Sensor %d OFFLINE\r\n",port);
			device_inserted_removed_callback(port,false);
			break;
		}
	}
		break;
	case BSP_SSR_OFFLINE:
	{
		if(bsp_sensor_config_table[port].model_type == 5983)
		{
			extern void start_MMC5983_data_read(uint8_t chip_select,uint8_t *buffer);
			start_MMC5983_data_read(cs,bsp_sensor_config_table[port].data_area);
		}
		if(bsp_sensor_config_table[port].model_type == 6)
		{
			void start_LSM6DSM_data_read(uint8_t chip_select, uint8_t *buffer);
			start_LSM6DSM_data_read(cs,bsp_sensor_config_table[port].data_area);
		}
		tos_set_timer(BSP_WAIT_SENSOR_MAX_TIME);
		soc_spi_request_rx(bsp_sensor_config_table[port].addr_or_cs,bsp_sensor_config_table[port].data_area,bsp_sensor_config_table[port].data_area,16);
		tos_set_state(BSP_SSR_ONLINE_READ);
	}
		break;
	case BSP_SSR_OFFLINE_TEST:
	{
		if(soc_spi_is_rx_full())
		{
			tos_set_timer(BSP_READ_SENSOR_INTERVAL);
			tos_set_state(BSP_SSR_ONLINE);
			bsp_spi_print("SPI Sensor %d ONLINE again\r\n",port);
			device_inserted_removed_callback(port,true);
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
/* end of task_spi.c */
