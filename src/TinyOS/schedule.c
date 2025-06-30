
/*------------------------------------
 * schedule.c
 * Create:  2025-06-29
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"
/*================================================================*/
unsigned int tos_this_pid;
unsigned int tos_this_tid;
/*------------------------------------*/
//if want to use tos, please call tos_set_pno in the entry of process or thread
//since tos doesn't schedule process now
void tos_set_pno(int pno);
void tos_set_pno(int pno)
{
	tos_this_tid = pno/TOS_MAX_PAT_NUM;
	tos_this_pid = pno%TOS_MAX_PAT_NUM;
}
/*------------------------------------*/
int tos_get_pno(void);
int tos_get_pno()
{
	int pno;
	pno = (tos_this_tid*TOS_MAX_PAT_NUM) + tos_this_pid;
	return pno;
}
/*================================================================*/
/* end of schedule.c */
