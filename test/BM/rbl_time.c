
/*------------------------------------
 * rbl_time.c
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

#include "..\0ctr.h"
#if SYS_TEST_IN_BM
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
