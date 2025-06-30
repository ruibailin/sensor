
/*------------------------------------
 * user.h
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


#ifndef TINYOS_USER_H_
#define TINYOS_USER_H_
/*================================================================*/
extern	int	tos_get_pno(void);
/*------------------------------------*/
extern	int	tos_get_state(void);
extern  int tos_get_last_state(void);
extern	void tos_set_state(int state);
/*------------------------------------*/
extern  void tos_set_timer(unsigned int length);
extern  void tos_clr_timer(void);
extern  void tos_set_timer_ex(int tid,unsigned int length);
extern  void tos_clr_timer_ex(int tid);
/*================================================================*/
#endif
/* end of user.h */
