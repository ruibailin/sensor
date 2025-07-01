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
static unsigned int old = 0;
unsigned int rbl_get_msec(void);
unsigned int rbl_get_msec()
{
	struct timeval current_time;
	gettimeofday(&current_time, 0x0L);
	unsigned int now;
	now = (unsigned int)(current_time.tv_usec/1000);
	if(old == 0)
	{
		old = now;
		return 0;
	}
	else
	{
		return now-old;
	}
}
/*================================================================*/
#endif
/* end of rbl_time.c */
