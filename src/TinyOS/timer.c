/*
 * timer.c
 *
 *  Created on: 10 20, 2023
 *      Author: stever
 */

#include "1imp.h"
/*================================================================*/
extern unsigned int tos_this_pid;
extern unsigned int tos_this_tid;
extern unsigned int rbl_get_msec(void);
/*------------------------------------*/
#define	TOS_MAX_TIMER_LEN	(0xffffffff/2)
int tos_is_time_up(unsigned int end);
int tos_is_time_up(unsigned int end)
{
	unsigned int now,timer;
	now = rbl_get_msec();
	timer = end - now;
	return (timer > TOS_MAX_TIMER_LEN);
}
/*------------------------------------*/
#define TOS_PROC_MAX_TIMER_NUM	4
typedef struct
{
	unsigned int timer[TOS_PROC_MAX_TIMER_NUM];
}TOS_T_T;
TOS_T_T	*tos_thread_timer[TOS_MAX_PAT_TYPE][TOS_MAX_PAT_NUM];
/*------------------------------------*/
#include <malloc.h>
#include <string.h>
/*------------------------------------*/
void tos_set_timer(unsigned int ll);
void tos_set_timer(unsigned int ll)
{
	TOS_T_T *thread;
	thread =tos_thread_timer[tos_this_tid][tos_this_pid];
	if(thread == 0x0L)
	{
		tos_thread_timer[tos_this_tid][tos_this_pid] = (TOS_T_T *)malloc(sizeof(TOS_T_T));
		memset(tos_thread_timer[tos_this_tid][tos_this_pid],0,sizeof(TOS_T_T));
		thread = tos_thread_timer[tos_this_tid][tos_this_pid];
	}
	thread->timer[0]=ll+rbl_get_msec();
}
void tos_clr_timer(void);
void tos_clr_timer()
{
	TOS_T_T *thread;
	thread =tos_thread_timer[tos_this_tid][tos_this_pid];
	if(thread == 0x0L)
		return;
	thread->timer[0]=0;
}
void tos_set_timer_ex(int td,unsigned int ll);
void tos_set_timer_ex(int td,unsigned int ll)
{
	if(td>=TOS_PROC_MAX_TIMER_NUM)
		return;
	TOS_T_T *thread;
	thread = tos_thread_timer[tos_this_tid][tos_this_pid];
	if(thread == 0x0L)
	{
		tos_thread_timer[tos_this_tid][tos_this_pid] = (TOS_T_T *)malloc(sizeof(TOS_T_T));
		memset(tos_thread_timer[tos_this_tid][tos_this_pid],0,sizeof(TOS_T_T));
		thread = tos_thread_timer[tos_this_tid][tos_this_pid];
	}
	thread->timer[td]=ll+rbl_get_msec();
}
void tos_clr_timer_ex(int td);
void tos_clr_timer_ex(int td)
{
	TOS_T_T *thread;
	thread =tos_thread_timer[tos_this_tid][tos_this_pid];
	thread->timer[td]=0;
}
/*------------------------------------*/
int tos_check_timer(void);
int tos_check_timer()
{
	TOS_T_T *thread;
	thread = tos_thread_timer[tos_this_tid][tos_this_pid];
	if(thread == 0x0L)
		return 0;

	int i;
	for(i=0;i<TOS_PROC_MAX_TIMER_NUM;i++)
	{
		if(thread->timer[i]==0)
			continue;
		if(!tos_is_time_up(thread->timer[i]))
			continue;
		thread->timer[i]=0;
		return i+1;	//0 has special meaning
	}
	return 0;
}
/*================================================================*/
/* end of timer.c */
