/*
 * rbl_time.c
 *
 *  Created on: Nov 28, 2023
 *      Author: stever
 */


#include "..\..\0ctr.h"
#if SYS_OS_CYGWIN
/*================================================================*/
#include <sys/time.h>
unsigned int rbl_get_msec(void);
unsigned int rbl_get_msec()
{
	struct timeval current_time;
	gettimeofday(&current_time, 0x0L);
	return (unsigned int)(current_time.tv_usec/1000);
}
/*================================================================*/
#endif
/* end of rbl_time.c */
