
/*------------------------------------
 * chipselection.c
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
#include "reg.h"	//also we can use hal.h
/*------------------------------------*/
static void *gpio_cs_port_addr[NUM_CHIP_SELECT_LINES];
static uint32_t gpio_cs_pin_value[NUM_CHIP_SELECT_LINES];
static uint32_t gpio_cs_pin_mask[NUM_CHIP_SELECT_LINES]={0x01,0x02,0x04,0x08};
/*------------------------------------*/
void soc_init_cs(void);
void soc_init_cs()
{
	int i;
	for(i=0;i<NUM_CHIP_SELECT_LINES;i++)
		reg_init_gpio(gpio_cs_port_addr[i],gpio_cs_pin_mask[i]);
}
/*------------------------------------*/
static void soc_clr_cs_gpio(int cs);
static void soc_clr_cs_gpio(int cs)
{
	uint32_t val;
	val = gpio_cs_pin_value[cs];
	val &= ~gpio_cs_pin_mask[cs];
	reg_write_gpio(gpio_cs_port_addr[cs],gpio_cs_pin_mask[cs],val);
	gpio_cs_pin_value[cs] = val;
}
static void soc_set_cs_gpio(int cs);
static void soc_set_cs_gpio(int cs)
{
	uint32_t val;
	val = gpio_cs_pin_value[cs];
	val |= gpio_cs_pin_mask[cs];
	reg_write_gpio(gpio_cs_port_addr[cs],gpio_cs_pin_mask[cs],val);
	gpio_cs_pin_value[cs] = val;
}

uint8_t soc_spi_cs;	//in current design, BSP no need to know chip selection,but OMMO API needs it
void soc_set_cs(int cs);
void soc_set_cs(int cs)
{
	if(cs>=NUM_CHIP_SELECT_LINES)
		return;		//should not go to here
	int i;
	for(i=0;i<NUM_CHIP_SELECT_LINES;i++)
		soc_clr_cs_gpio(i);	//make sure only one chip is selected
	soc_set_cs_gpio(cs);
	soc_spi_cs = cs;
}
/*------------------------------------*/
void soc_deinit_cs(void);
void soc_deinit_cs()
{
	int i;
	for(i=0;i<NUM_CHIP_SELECT_LINES;i++)
		reg_deinit_gpio(gpio_cs_port_addr[i],gpio_cs_pin_mask[i]);
}

/*================================================================*/
/* end of chipselection.c */
