/*
 * rbl_time.c
 *
 *  Created on: Nov 28, 2023
 *      Author: stever
 */



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
/* end of rbl_time.c */
