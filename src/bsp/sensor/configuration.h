
/*------------------------------------
 * configuration.h
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


#ifndef BSP_SENSOR_CONFIGURATION_H_
#define BSP_SENSOR_CONFIGURATION_H_
/*================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------*/
#define BSP_MAX_SENSOR_PORT		5
#define BSP_MAX_SENSOR_MODEL	3
/*------------------------------------*/
typedef enum{
	BSP_NULL_SENSOR = 0,
	BSP_I2C_SENSOR,
	BSP_SPI_SENSOR
}BSP_Sensor_Connect_Enum;
/*------------------------------------*/
typedef void (*bsp_init_sensor_t)(uint32_t code);
typedef void (*bsp_read_sensor_t)(uint8_t port_num, uint8_t *data);
typedef void (*bsp_write_sendor_t)(uint8_t port_num, uint8_t *data);
typedef void (*bsp_insert_sensor_t)(uint8_t port_num);
typedef void (*bsp_remove_sensor_t)(uint8_t port_num);
/*------------------------------------*/
typedef struct{
	bool configured;
	bool inserted;
	BSP_Sensor_Connect_Enum	con_type;
	uint8_t	addr_or_cs;
	uint32_t model_type;
	bsp_init_sensor_t ssr_init;
	bsp_read_sensor_t ssr_read;
	bsp_write_sendor_t ssr_write;
	bsp_insert_sensor_t ssr_insert;
	bsp_remove_sensor_t ssr_remove;
	MRB *tx_messege_buf;
	uint8_t *data_area;
	void *descriptor;
}BSP_Sensor_Config_t;
/*------------------------------------*/
extern BSP_Sensor_Config_t bsp_sensor_config_table[BSP_MAX_SENSOR_PORT];
/*------------------------------------*/
#define BSP_MAX_SENSOR_DATA_AREA_SIZE	256
/*================================================================*/
#endif
/* end of configuration.h */
