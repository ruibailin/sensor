
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
extern void TIMER_ISR(void);
extern void I2C_ISR(bool success);
extern void SPI_ISR(void);
/*------------------------------------*/
void *TIMER_ISR_pthread_entry(void *arg);
void *TIMER_ISR_pthread_entry(void *arg)
{
	while(1)
	{
		usleep(100000);		//delay 100ms
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
		I2C_ISR();
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
void sys_init_test_thread(void);
void sys_init_test_thread()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid, (void *)0L, TIMER_ISR_pthread_entry, 0x0L);
	if(ret == 0)
		printf("Timer MOCK ISR created %d\r\n",tid);
	ret = pthread_create(&tid, (void *)0L, I2C_ISR_pthread_entry, 0x0L);
	if(ret == 0)
		printf("I2C MOCK ISR created %d\r\n",tid);
	ret = pthread_create(&tid, (void *)0L, SPI_ISR_pthread_entry, 0x0L);
	if(ret == 0)
		printf("SPI MOCK ISR created %d\r\n",tid);
}
/*================================================================*/
#endif
/* end of thread.c */
