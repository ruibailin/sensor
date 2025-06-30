
/*------------------------------------
 * reg.h
 * Create:  2025-06-28
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
#ifndef SOC_GPIO_REG_H_
#define SOC_GPIO_REG_H_
/*================================================================*/
extern void reg_init_gpio(void *port_addr,uint32_t pin_mask);
extern uint32_t reg_read_gpio(void *port_addr,uint32_t pin_mask);
extern void reg_write_gpio(void *port_addr,uint32_t pin_mask,uint32_t val);
extern void reg_deinit_gpio(void *port_addr,uint32_t pin_mask);
/*------------------------------------*/

/*================================================================*/
#endif
/* end of reg.h */
