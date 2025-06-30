
/*------------------------------------
 * hal.h
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
#ifndef SOC_GPIO_HAL_H_
#define SOC_GPIO_HAL_H_
/*================================================================*/
extern void hal_gpio_init(char port_name,unsigned char pin_index);
extern void hal_set_gpio_output(char port_name,unsigned char pin_index,bool state);
extern bool hal_get_gpio_input(char port_name,unsigned char pin_index);
extern void hal_gpio_deinit(char port_name,unsigned char pin_index);
/*------------------------------------*/

/*================================================================*/
#endif
/* end of hal.h */
