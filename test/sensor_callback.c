
/*------------------------------------
 * sensor_callback.c
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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/*------------------------------------*/
void (*device_inserted_removed_callback)(uint8_t port_num, bool device_inserted);
void test_device_inserted_removed_callback(uint8_t port_num, bool device_inserted);
void test_device_inserted_removed_callback(uint8_t port_num, bool device_inserted)
{
	if(device_inserted)
	{
		printf("sensor on port %d inserted!\r\n",port_num);
	}
	else
	{
		printf("sensor on port %d removed!\r\n",port_num);
	}
}
/*------------------------------------*/
void (*data_read_callback)(uint8_t port_num, uint8_t *data);
void test_data_read_callback(uint8_t port_num, uint8_t *data);
void test_data_read_callback(uint8_t port_num, uint8_t *data)
{
	printf("sensor data on port %d received!\r\n",port_num);
	extern void rbl_log_hex(unsigned char *data, int size);
	rbl_log_hex(data,24);
}
/*================================================================*/
/* end of sensor_callback.c */
