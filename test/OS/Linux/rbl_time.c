/*
 * rbl_time.c
 *
 *  Created on: Nov 28, 2023
 *      Author: stever
 */


#include "..\..\0ctr.h"
#if SYS_OS_LINUX
/*================================================================*/
#include <sys/time.h>
static suseconds_t	old_us = 0;
time_t		old_s = 0;
unsigned int rbl_get_msec(void);
unsigned int rbl_get_msec()
{
	struct timeval current_time;
	gettimeofday(&current_time, 0x0L);
	unsigned int ms;
	if(old_s == 0)
	{
		old_us = current_time.tv_sec;
		old_s = current_time.tv_sec;
		return 0;
	}
	else
	{
		if(old_s<current_time.tv_sec)
			ms = (current_time.tv_sec-old_s)/1000;
		else
			ms = (1000000+current_time.tv_sec-old_s)/1000;
		ms += (current_time.tv_sec-old_s)*1000;
		return ms;
	}
}
/*================================================================*/
#endif
/* end of rbl_time.c */
