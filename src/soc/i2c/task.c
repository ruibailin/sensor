
/*------------------------------------
 * task.c
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

#include "1imp.h"
/*================================================================*/
uint8_t *soc_i2c_tx_data;
uint8_t soc_i2c_tx_len;
uint8_t soc_i2c_tx_addr;

uint8_t *soc_i2c_cmd_data;
uint8_t soc_i2c_cmd_len;
uint8_t soc_i2c_rx_addr;
uint8_t *soc_i2c_rx_data;
uint8_t soc_i2c_rx_len;

bool soc_i2c_is_tx_idle(void);
bool soc_i2c_is_tx_idle()
{
	return (soc_i2c_tx_len == 0);
}
void soc_i2c_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len);
void soc_i2c_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len)
{
	soc_i2c_tx_len = tx_len;
	soc_i2c_tx_data = tx_data;
	soc_i2c_tx_addr = address;
}
void soc_i2c_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len);
void soc_i2c_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len)
{
	soc_i2c_cmd_len = cmd_len;
	soc_i2c_cmd_data = cmd_data;
	soc_i2c_rx_addr = address;
}

bool soc_i2c_is_rx_full(void);
bool soc_i2c_is_rx_full()
{
	return (soc_i2c_rx_len != 0);
}
#include "hal.h"
#include "reg.h"
uint8_t soc_i2c_copy_rx_data(uint8_t *rx_data);
uint8_t soc_i2c_copy_rx_data(uint8_t *rx_data)
{
	uint8_t rx_len;
	if(hal_dma_read_rx_i2c_device(soc_i2c_rx_addr,rx_data, &rx_len))
		return rx_len;
	return 0;
}

/*------------------------------------*/
#include "tos.h"
/*------------------------------------*/
typedef enum{
	I2C_IDLE_STATE = 0,
	I2C_TX_STATE,
	I2C_RX_STATE,
	I2C_TX_ERROR,
	I2C_RX_ERROR
}I2C_Machine_State;
/*------------------------------------*/
void soc_i2c_int_thread();
void soc_i2c_int_thread()
{
	tos_set_pno(SOC_I2C_TASK_PNO);
	int ss;
	ss = tos_get_state();
	switch(ss)
	{
	case I2C_IDLE_STATE:
		break;	//we should not go here
	case I2C_TX_STATE:
	{
		soc_i2c_tx_len = 0;	//transmission finished
	}
		break;
	case I2C_RX_STATE:
	{
		hal_dma_read_rx_i2c_device(soc_i2c_rx_addr,0x0L,&soc_i2c_rx_len);
	}
		break;
	case I2C_TX_ERROR:
		break;
	case I2C_RX_ERROR:
		break;
	default:
		break;
	}
}

/*------------------------------------*/
#include "0ctr.h"
#define SOC_I2C_TX_TIME_OUT		300
#define SOC_I2C_RX_TIME_OUT		500
void soc_i2c_loop_thread();
void soc_i2c_loop_thread()
{
	tos_set_pno(SOC_I2C_TASK_PNO);
	int ss;
	ss = tos_get_state();
	switch(ss)
	{
	case I2C_IDLE_STATE:
	{
		if(soc_i2c_tx_len!=0)
		{
#if I2C_USE_OMMO_HAL
extern void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
			start_i2c_transfer(soc_i2c_tx_addr, soc_i2c_tx_data, 0x0L, soc_i2c_tx_len);
#else
			 hal_dma_start_tx_i2c_device(soc_i2c_tx_addr,soc_i2c_tx_data, soc_i2c_tx_len);
#endif
			 tos_set_timer(SOC_I2C_TX_TIME_OUT);
			 tos_set_state(I2C_TX_STATE);
			 break;
		}
		if(soc_i2c_cmd_len!=0)
		{
#if I2C_USE_OMMO_HAL
extern void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
			start_i2c_transfer(soc_i2c_rx_addr, soc_i2c_cmd_data, soc_i2c_rx_data, soc_i2c_cmd_len);
#else
			 hal_dma_start_rx_i2c_device(soc_i2c_rx_addr,soc_i2c_cmd_data, soc_i2c_cmd_len);
#endif
			 tos_set_timer(SOC_I2C_RX_TIME_OUT);
			 tos_set_state(I2C_RX_STATE);
			 break;
		}
	}
		break;
	case I2C_TX_STATE:
	{
		if(soc_i2c_tx_len == 0)
		{
			tos_set_state(I2C_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(!tos_check_timer())
			break;
		 tos_set_state(I2C_TX_ERROR);
	}
		break;
	case I2C_RX_STATE:
	{
		if(soc_i2c_cmd_len == 0)
		{
			tos_set_state(I2C_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(soc_i2c_rx_len != 0)
		{
			tos_set_state(I2C_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(!tos_check_timer())
			break;
		 tos_set_state(I2C_RX_ERROR);
	}
		break;
	case I2C_TX_ERROR:
	{
		hal_dma_init_i2c_bus();
		soc_i2c_tx_len = 0;
	}
		break;
	case I2C_RX_ERROR:
	{
		hal_dma_init_i2c_bus();
		soc_i2c_rx_len = 0;
		soc_i2c_cmd_len = 0;
	}
		break;
	default:
		break;
	}
}
/*------------------------------------*/

/*================================================================*/
/* end of task.c */
