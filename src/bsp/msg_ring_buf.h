
/*------------------------------------
 * msg_ring_buf.h
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


#ifndef BSP_MSG_RING_BUF_H_
#define BSP_MSG_RING_BUF_H_
/*================================================================*/
#include <stdint.h>
#include <stdbool.h>
/*------------------------------------*/
typedef struct
{
	uint8_t head;
	uint8_t tail;
	uint8_t size;
	uint8_t save;		//for word alignment and debug
	void **messege;
}MRB;
/*------------------------------------*/
extern MRB *mrb_init(uint8_t max_size);
extern void *mrb_pop_msg(MRB *mrb);
extern void mrb_push_msg(MRB *mrb,void *msg);
extern bool mrb_is_full(MRB *mrb);
extern bool mrb_is_empty(MRB *mrb);
extern uint8_t mrb_get_empty_size(MRB *mrb);
extern uint8_t mrb_get_occupied_szie(MRB *mrb);
extern void *mrb_push_msg_drop(MRB *mrb,void *msg);
/*================================================================*/
#endif
/* end of msg_ring_buf.h */
