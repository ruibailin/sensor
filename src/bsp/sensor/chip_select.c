
/*------------------------------------
 * chip_select.c
 * Create:  2025-06-30
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
static uint8_t bsp_valid_cs[4]={1,2,4,8};
static uint8_t bsp_current_cs=0;
/*------------------------------------*/
uint8_t bsp_get_cs(void);
uint8_t bsp_get_cs()
{
	return bsp_valid_cs[bsp_current_cs];
}

/*------------------------------------*/
static bool bsp_is_spi_task_safe(int state);
static bool bsp_is_spi_task_safe(int state)
{
	switch(state)
	{
	case BSP_SSR_INIT:
		return true;
		break;
	case BSP_SSR_ONLINE:
		return true;
		break;
	case BSP_SSR_ONLINE_READ:
		break;
	case BSP_SSR_ONLINE_WRITE:
		break;
	case BSP_SSR_OFFLINE:
		return true;
		break;
	case BSP_SSR_OFFLINE_TEST:
		break;
	default:
		break;
	}
	return false;
}

#include "tos.h"
extern bool soc_spi_is_tx_idle(void);
void bsp_inc_cs(void);
void bsp_inc_cs()
{
	if(!soc_spi_is_tx_idle())
		return;		//if spi bus is busy to transmit,can't change
	int pno,state;
	pno = BSP_SSR_SPI_PNO+bsp_current_cs;
	tos_set_pno(pno);
	state = tos_get_state();
	if(!bsp_is_spi_task_safe(state))
		return;	   //Need wait
	bsp_current_cs++;
	if(bsp_current_cs>=sizeof(bsp_valid_cs))
		bsp_current_cs = 0x00;
}
/*================================================================*/
/* end of chip_select.c */
