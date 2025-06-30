
/*------------------------------------
 * hal.c
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
#if OMMO_DEBUG_GPIO
#define gpio_print(x...)	printf(x)
#else
#define gpio_print(x...)
#endif
/*------------------------------------*/
#include "reg.h"
//example of HAL,please refer to SOC manual
static void *gpio_all_port_addr[SOC_MAX_GPIO_PORT_NUM];
static uint32_t gpio_all_port_output_value[SOC_MAX_GPIO_PORT_NUM];
static uint32_t gpio_all_pin_mask[SOC_MAX_PIN_PER_PORT];
void hal_gpio_init(char port_name,unsigned char pin_index);
void hal_gpio_init(char port_name,unsigned char pin_index)
{
	gpio_print("GPIO Init Port %c Pin %d\r\n",port_name,pin_index);
}
/*------------------------------------*/
void hal_set_gpio_output(char port_name,unsigned char pin_index,bool state);
void hal_set_gpio_output(char port_name,unsigned char pin_index,bool state)
{
	if(port_name <'A')
		return;	//should not got to hear
	if(port_name >= SOC_MAX_GPIO_PORT_NAME)
		return;
	if(pin_index>=SOC_MAX_PIN_PER_PORT)
		return;
	uint32_t val;
	int port;
	port = port_name - 'A';
	val = gpio_all_port_output_value[port];
	if(state)
		val |= gpio_all_pin_mask[port];
	else
		val &= ~gpio_all_pin_mask[port];
	reg_write_gpio(gpio_all_port_addr[port],gpio_all_pin_mask[port],val);
	gpio_all_port_output_value[port] = val;
	if(state)
		gpio_print("GPIO Port %c Pin %d Output ON\r\n",port_name,pin_index);
	else
		gpio_print("GPIO Port %c Pin %d Output OFF\r\n",port_name,pin_index);
}
/*------------------------------------*/
bool hal_get_gpio_input(char port_name,unsigned char pin_index);
bool hal_get_gpio_input(char port_name,unsigned char pin_index)
{
	if(port_name <'A')
		return false;	//should not got to hear
	if(port_name >= SOC_MAX_GPIO_PORT_NAME)
		return false;
	if(pin_index>=SOC_MAX_PIN_PER_PORT)
		return false;
	uint32_t val;
	int port;
	port = port_name - 'A';
	val = reg_read_gpio(gpio_all_port_addr[port],gpio_all_pin_mask[pin_index]);
	val &= gpio_all_pin_mask[port];
	if(val)
		gpio_print("GPIO Port %c Pin %d Input ON\r\n",port_name,pin_index);
	else
		gpio_print("GPIO Port %c Pin %d Input OFF\r\n",port_name,pin_index);
	if(val)
		return true;
	else
		return false;
}
/*------------------------------------*/
void hal_gpio_deinit(char port_name,unsigned char pin_index);
void hal_gpio_deinit(char port_name,unsigned char pin_index)
{
	gpio_print("GPIO DeInit Port %c Pin %d\r\n",port_name,pin_index);
}
/*================================================================*/
/* end of hal.c */
