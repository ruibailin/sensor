/*
 * state.c
 *
 *  Created on: Sep 8, 2023
 *      Author: stever
 */

#include "1imp.h"
/*================================================================*/
extern unsigned int tos_this_pid;
extern unsigned int tos_this_tid;
/*------------------------------------*/
typedef struct
{
	int this_state;
	int last_state;
}TOS_S_T;
TOS_S_T	tos_thread_state[TOS_MAX_PAT_TYPE][TOS_MAX_PAT_NUM];
/*------------------------------------*/
void tos_ini_state(int tid,int pid);
void tos_ini_state(int tid,int pid)
{
	tos_thread_state[tid][pid].this_state = 0;
	tos_thread_state[tid][pid].last_state = 0;
}
/*------------------------------------*/
void tos_print_state(void);
void tos_print_state()
{
	TOS_S_T *thread;
	thread =(TOS_S_T  *)&tos_thread_state[tos_this_tid][tos_this_pid];
	tos_print("TOS STATE:tid %d pid %d this_state %d\r\n",tos_this_tid,tos_this_pid,thread->this_state);
}
/*------------------------------------*/
void tos_set_state(int ss);
void tos_set_state(int ss)
{
	TOS_S_T *thread;
	thread =(TOS_S_T  *)&tos_thread_state[tos_this_tid][tos_this_pid];
	thread->last_state = thread->this_state;
	thread->this_state=ss;
}
int tos_get_state(void);
int tos_get_state()
{
	TOS_S_T *thread;
	thread =(TOS_S_T  *)&tos_thread_state[tos_this_tid][tos_this_pid];
	return thread->this_state;
}

int tos_get_last_state(void);
int tos_get_last_state()
{
	TOS_S_T *thread;
	thread =(TOS_S_T  *)&tos_thread_state[tos_this_tid][tos_this_pid];
	return thread->last_state;
}
/*================================================================*/
/* end of state.c */
