
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
#if SYS_OS_LINUX
/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
/*------------------------------------*/
extern void TIMER_ISR(void);
extern void I2C_ISR(bool success);
extern void SPI_ISR(void);
/*------------------------------------*/
void *TIMER_ISR_pthread_entry(void *arg);
void *TIMER_ISR_pthread_entry(void *arg)
{
	while(1)
	{
		usleep(1000);		//delay 100ms
		TIMER_ISR();
	}
	return 0x0L;
}

void *I2C_ISR_pthread_entry(void *arg);
void *I2C_ISR_pthread_entry(void *arg)
{
	while(1)
	{
		usleep(100);		//delay 100us
		I2C_ISR(true);
	}
	return 0x0L;
}

void *SPI_ISR_pthread_entry(void *arg);
void *SPI_ISR_pthread_entry(void *arg)
{
	while(1)
	{
		usleep(100);		//delay 100us
		SPI_ISR();
	}
	return 0x0L;
}
/*------------------------------------*/
extern char sys_input_cmd;
extern void sys_parse_input(char cmd);
void *input_pthread_entry(void *arg);
void *input_pthread_entry(void *arg)
{
	int cc;
	char cmd;
	cc = 0;
	while(1)
	{
		usleep(100);		//delay 100us
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
	TIMER_ISR();
	I2C_ISR(true);
	SPI_ISR();

	pthread_t tid;
	int ret;
	ret = 0;
	ret = pthread_create(&tid, (void *)0L, TIMER_ISR_pthread_entry, 0x0L);
	if(ret == 0)
	{
		printf("Timer MOCK ISR created\r\n");
	}
	ret = pthread_create(&tid, (void *)0L, I2C_ISR_pthread_entry, 0x0L);
	if(ret == 0)
	{
		printf("I2C MOCK ISR created\r\n");
	}
	ret = pthread_create(&tid, (void *)0L, SPI_ISR_pthread_entry, 0x0L);
	if(ret == 0)
	{
		printf("SPI MOCK ISR created\r\n");
	}
	ret = pthread_create(&tid, (void *)0L, input_pthread_entry, 0x0L);
	if(ret == 0)
	{
		printf("Key Input Thread created\r\n");
	}
}
/*================================================================*/
#endif
/* end of thread.c */
