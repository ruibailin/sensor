
/*------------------------------------
 * reg.c
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
/*================================================================*/
#include "0ctr.h"
#if SYS_DEBUG_GPIO
#define gpio_print(x...)	printf(x)
#else
#define gpio_print(x...)
#endif
/*------------------------------------*/
//example of register level function,please refer to SOC manual
void reg_init_gpio(void *port_addr,uint32_t pin_mask);
void reg_init_gpio(void *port_addr,uint32_t pin_mask)
{
	gpio_print("GPIO Init\r\n");
}
/*------------------------------------*/
uint32_t reg_read_gpio(void *port_addr,uint32_t pin_mask);
uint32_t reg_read_gpio(void *port_addr,uint32_t pin_mask)
{
	gpio_print("GPIO read\r\n");
	return 0;
}
/*------------------------------------*/
void reg_write_gpio(void *port_addr,uint32_t pin_mask,uint32_t val);
void reg_write_gpio(void *port_addr,uint32_t pin_mask,uint32_t val)
{
	gpio_print("GPIO write\r\n");
}
/*------------------------------------*/
void reg_deinit_gpio(void *port_addr,uint32_t pin_mask);
void reg_deinit_gpio(void *port_addr,uint32_t pin_mask)
{
	gpio_print("GPIO deinit\r\n");
}
/*================================================================*/
/* end of reg.c */
