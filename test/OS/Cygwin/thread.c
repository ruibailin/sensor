
/*------------------------------------
 * thread.c
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
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
/*------------------------------------*/
extern void sys_parse_input(char cmd);
extern char sys_input_cmd;
void *pthread_entry(void *arg);
void *pthread_entry(void *arg)
{
	int cc;
	char cmd;
	while(1)
	{
		cc = getchar();
		cmd = (char )cc;
		sys_parse_input(cmd);
		sys_input_cmd = cmd;
	}
	return 0x0L;
}
/*------------------------------------*/
void sys_init_test_thread(void);
void sys_init_test_thread()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid, (void *)0L, pthread_entry, 0x0L);
	if(ret == 0)
	{
		printf("Key Input thread created\r\n");
	}
}
/*================================================================*/
#endif
/* end of thread.c */
