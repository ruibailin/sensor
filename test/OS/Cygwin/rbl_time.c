/*
 * rbl_time.c
 *
 *  Created on: Nov 28, 2023
 *      Author: stever
 */


#include "..\..\0ctr.h"
#if SYS_OS_CYGWIN
/*================================================================*/
extern unsigned int sys_ticks;
/*------------------------------------*/
unsigned int rbl_get_msec();
unsigned int rbl_get_msec()
{
	return sys_ticks;
}
/*================================================================*/
#endif
/* end of rbl_time.c */
