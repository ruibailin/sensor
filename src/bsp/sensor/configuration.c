
/*------------------------------------
 * configuration.c
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
#include "configuration.h"
BSP_Sensor_Config_t bsp_sensor_config_table[BSP_MAX_SENSOR_PORT]={
		{true,false,BSP_I2C_SENSOR,5,5603,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},
		{true,false,BSP_SPI_SENSOR,1,5983,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},
		{false,false,0,2,0,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},
		{true,true,BSP_SPI_SENSOR,4,6,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},
		{false,false,0,8,0,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}
};
/*------------------------------------*/
void bsp_init_sensor_data(int port);
void bsp_init_sensor_data(int port)
{
	if(bsp_sensor_config_table[port].configured == false)
		return;
	if(bsp_sensor_config_table[port].con_type == BSP_I2C_SENSOR)
	{
		bsp_sensor_config_table[port].data_area = malloc(BSP_MAX_SENSOR_DATA_AREA_SIZE);
		bsp_sensor_config_table[port].tx_messege_buf = mrb_init(16);
		bsp_sensor_config_table[port].ssr_init = 0x0L;
		bsp_sensor_config_table[port].ssr_insert = 0x0L;
		bsp_sensor_config_table[port].ssr_read = 0x0L;
		bsp_sensor_config_table[port].ssr_remove = 0x0L;
		bsp_sensor_config_table[port].ssr_write = 0x0L;
	}
	if(bsp_sensor_config_table[port].con_type == BSP_SPI_SENSOR)
	{
		bsp_sensor_config_table[port].data_area = malloc(BSP_MAX_SENSOR_DATA_AREA_SIZE);
		bsp_sensor_config_table[port].tx_messege_buf = mrb_init(8);
		bsp_sensor_config_table[port].ssr_init = 0x0L;
		bsp_sensor_config_table[port].ssr_insert = 0x0L;
		bsp_sensor_config_table[port].ssr_read = 0x0L;
		bsp_sensor_config_table[port].ssr_remove = 0x0L;
		bsp_sensor_config_table[port].ssr_write = 0x0L;
	}
}
/*================================================================*/
/* end of configuration.c */
