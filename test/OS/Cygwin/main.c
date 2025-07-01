
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

#include "..\..\0ctr.h"
#if SYS_OS_CYGWIN
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
extern void sys_print_usage(void);
extern void sys_init_term(void);
extern void sys_init_test_thread(void);
/*------------------------------------*/
unsigned int sys_loop=0;
unsigned int sys_ticks=0;
unsigned int sys_ms=0;
#define MAX_LOOP_TIME_PER_MS	800000

char sys_input_cmd;
unsigned int speedup=1;
unsigned int speeddown=1;
int main(void)
{
	device_inserted_removed_callback = test_device_inserted_removed_callback;
	data_read_callback = test_data_read_callback;
	start_timer();
	sys_print_usage();
	sys_init_term();
	sys_init_test_thread();
	unsigned int speed;
	speed = MAX_LOOP_TIME_PER_MS;
	speed /= speeddown;
	speed *= speedup;
	while(1)
	{
		if(sys_input_cmd == 'q')
			break;
		speed = MAX_LOOP_TIME_PER_MS;
		speed /= speedup;
		speed *= speeddown;

		sys_loop++;
		I2C_ISR(true);
		SPI_ISR();

		if(sys_loop<speed)
			continue;
		sys_loop=0;
		sys_ticks++;
		sys_ms++;
		if(sys_ms<100)
			continue;
		sys_ms=0;
		TIMER_ISR();
	}
	extern void sys_restore_term(void);
	sys_restore_term();
	return EXIT_SUCCESS;
}
/*================================================================*/
#endif
/* end of main.c */
