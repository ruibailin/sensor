
/*------------------------------------
 * main.c
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

#include "..\0ctr.h"
#if SYS_TEST_IN_BM
/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/*------------------------------------*/
extern void (*device_inserted_removed_callback)(uint8_t port_num, bool device_inserted);
extern void test_device_inserted_removed_callback(uint8_t port_num, bool device_inserted);
extern void (*data_read_callback)(uint8_t port_num, uint8_t *data);
extern void test_data_read_callback(uint8_t port_num, uint8_t *data);
/*------------------------------------*/
extern void TIMER_ISR(void);
extern void I2C_ISR(bool success);
extern void SPI_ISR(void);
extern void start_timer(void);
/*------------------------------------*/
unsigned int sys_loop=0;
unsigned int sys_ticks=0;
unsigned int sys_ms=0;
int main(void)
{
	device_inserted_removed_callback = test_device_inserted_removed_callback;
	data_read_callback = test_data_read_callback;
	start_timer();
	while(1)
	{
		sys_loop++;
		I2C_ISR(true);
		SPI_ISR();
		if(sys_loop<800000)
			continue;
		sys_loop=0;
		sys_ticks++;
		sys_ms++;
		if(sys_ms<100)
			continue;
		sys_ms=0;
		TIMER_ISR();
	}
	return EXIT_SUCCESS;
}
/*================================================================*/
#endif
/* end of main.c */
