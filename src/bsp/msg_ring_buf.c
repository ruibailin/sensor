
/*------------------------------------
 * msg_ring_buf.c
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

#include "msg_ring_buf.h"
/*================================================================*/
#include "0ctr.h"
#if SYS_DEBUG_MRB
#define MAX_MRB_NUM	16
#include <stdio.h>
MRB *mrb_table[MAX_MRB_NUM];
#define mrb_print(x...)	printf(x)
void mrb_record(MRB *mrb);
void mrb_record(MRB *mrb)
{
	int i;
	for(i=0;i<MAX_MRB_NUM;i++)
	{
		if(mrb_table!=0x0L)
			continue;
		mrb_table[i] = mrb;
	}
	mrb_print("Too many MRB\r\n");
}
#else
#define mrb_print(x...)
#define mrb_record(x)
#endif

#include <malloc.h>
MRB *mrb_init(uint8_t max_size);
MRB *mrb_init(uint8_t max_size)
{
	MRB *mrb;
	mrb = malloc(sizeof(MRB));
	if(mrb == 0x0L)
		return mrb;
	mrb->size = max_size;
	mrb->messege = malloc(max_size * sizeof(void *));
	mrb->head=0;
	mrb->tail=0;
	mrb_record(mrb);
	return mrb;
}
/*------------------------------------*/
void mrb_inc_head(MRB *mrb);
void mrb_inc_head(MRB *mrb)
{
	mrb->head ++;
	if(mrb->head<mrb->size)
		return;
	mrb->head = 0;
}
void mrb_dec_head(MRB *mrb);
void mrb_dec_head(MRB *mrb)
{
	mrb->head --;
	if(mrb->head<mrb->size)
		return;
	mrb->head = mrb->size-1;
}
void mrb_inc_tail(MRB *mrb);
void mrb_inc_tail(MRB *mrb)
{
	mrb->tail ++;
	if(mrb->tail<mrb->size)
		return;
	mrb->tail = 0;
}
void mrb_dec_tail(MRB *mrb);
void mrb_dec_tail(MRB *mrb)
{
	mrb->tail --;
	if(mrb->tail<mrb->size)
		return;
	mrb->tail = mrb->size-1;
}
/*------------------------------------*/
void *mrb_pop_msg(MRB *mrb);
void *mrb_pop_msg(MRB *mrb)
{
	if(mrb == 0x0L)
		return 0x0L;	//should not happen
	if(mrb->messege == 0x0L)
		return 0x0L; //should not happen
	if(mrb->tail==mrb->head)
		return 0x0L; //no new message
	void *msg;
	msg = mrb->messege[mrb->tail];
	mrb_inc_tail(mrb);
	mrb_print("MRB %x POP\r\n",(uint32_t)mrb);
	return(msg);
}
void mrb_push_msg(MRB *mrb,void *msg);
void mrb_push_msg(MRB *mrb,void *msg)
{
	if(mrb == 0x0L)
		return;	//should not happen
	if(mrb->messege == 0x0L)
		return; //should not happen
	mrb->messege[mrb->head] = msg;
	mrb_print("MRB %x PUSH\r\n",(uint32_t)mrb);
	mrb_inc_head(mrb);
}
/*------------------------------------*/
bool mrb_is_full(MRB *mrb);
bool mrb_is_full(MRB *mrb)
{
	if(mrb == 0x0L)
		return true;	//should not happen
	uint8_t tail;
	tail=mrb->tail;
	tail++;

	if(tail<mrb->size)
		mrb->tail=tail;
	else
		tail=0;

	if(tail==mrb->head)
		return true;
	else
		return false;
}

bool mrb_is_empty(MRB *mrb);
bool mrb_is_empty(MRB *mrb)
{
	if(mrb == 0x0L)
		return true;	//should not happen
	return (mrb->tail==mrb->head);
}

uint8_t mrb_get_empty_size(MRB *mrb);
uint8_t mrb_get_empty_size(MRB *mrb)
{
	if(mrb == 0x0L)
		return 0;	//should not happen
	uint8_t len;
	if(mrb->head<mrb->tail)
	{
		len = mrb->tail-mrb->head;
		len --;
		return len;
	}
	len = mrb->size-mrb->head;
	len += mrb->tail;
	len --;
	return len;
}

uint8_t mrb_get_occupied_szie(MRB *mrb);
uint8_t mrb_get_occupied_szie(MRB *mrb)
{
	if(mrb == 0x0L)
		return 0;	//should not happen
	uint8_t size;
	if(mrb->tail>mrb->head)
	{
		size = mrb->size-mrb->tail;
		size += mrb->head;
		return size;
	}
	size = mrb->head-mrb->tail;
	return size;
}
/*------------------------------------*/
void *mrb_push_msg_drop(MRB *mrb,void *msg);
void *mrb_push_msg_drop(MRB *mrb,void *msg)
{
	if(mrb == 0x0L)
		return 0x0L;	//should not happen
	if(mrb->messege == 0x0L)
		return 0x0L; //should not happen
	 void *drop;
	 if(mrb_is_full(mrb))
	 {
		 drop = mrb_pop_msg(mrb);
		 mrb_print("MRB %x PUSH DROP\r\n",(uint32_t)mrb);
	 }
	 else
	 {
		 drop = 0x0L;
	 }

	 mrb_push_msg(mrb,msg);
	 mrb_print("MRB %x PUSH\r\n",(uint32_t)mrb);
	 return drop;	//The caller should be responsible to free drop
}
/*================================================================*/
/* end of msg_ring_buf.c */
