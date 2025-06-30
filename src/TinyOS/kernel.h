
/*------------------------------------
 * kernel.h
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



#ifndef TINYOS_KERNEL_H_
#define TINYOS_KERNEL_H_
/*================================================================*/
extern	void tos_set_pno(int pno);
/*------------------------------------*/
extern void tos_ini_state(int tid,int pid);
extern int tos_check_timer(void);
/*================================================================*/
#endif
/* end of kernel.h */
