
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
#if SYS_OS_LINUX
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
extern void start_timer(void);
extern void sys_init_test_thread(void);
extern void sys_init_term(void);
extern void sys_print_usage();
unsigned int speedup=1;
unsigned int speeddown=1;
char sys_input_cmd;
/*------------------------------------*/
int main(int argc, char **argv)
{
	device_inserted_removed_callback = test_device_inserted_removed_callback;
	data_read_callback = test_data_read_callback;
	start_timer();
	sys_print_usage();
	sys_init_term();
	sys_init_test_thread();
	while(1)
	{
		if(sys_input_cmd == 'q')
			break;
	}
	extern void sys_restore_term(void);
	sys_restore_term();
	return EXIT_SUCCESS;
}
/*================================================================*/
#endif
/* end of main.c */
