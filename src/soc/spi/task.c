
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
uint8_t *soc_spi_tx_data;
uint8_t soc_spi_tx_len;

uint8_t *soc_spi_cmd_data;
uint8_t soc_spi_cmd_len;
uint8_t *soc_spi_rx_data;
uint8_t soc_spi_rx_len;


bool soc_spi_is_tx_idle(void);
bool soc_spi_is_tx_idle()
{
	return (soc_spi_tx_len == 0);
}

//For SPI, address is useless,just put 0 for unified interface,
void soc_spi_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len);
void soc_spi_request_tx(uint8_t address,uint8_t *tx_data, uint8_t tx_len)
{
	soc_spi_tx_len = tx_len;
	soc_spi_tx_data = tx_data;
}
void soc_spi_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len);
void soc_spi_request_rx(uint8_t address,uint8_t *cmd_data, uint8_t cmd_len)
{
	soc_spi_cmd_len = cmd_len;
	soc_spi_cmd_data = cmd_data;
}

bool soc_spi_is_rx_full(void);
bool soc_spi_is_rx_full()
{
	return (soc_spi_rx_len != 0);
}
#include "hal.h"
#include "reg.h"
uint8_t soc_spi_copy_rx_data(uint8_t *rx_data);
uint8_t soc_spi_copy_rx_data(uint8_t *rx_data)
{
	uint8_t rx_len;
	if(hal_dma_read_rx_spi_device(rx_data, &rx_len))
		return rx_len;
	return 0;
}

/*------------------------------------*/
#include "tos.h"
/*------------------------------------*/
typedef enum{
	SPI_IDLE_STATE = 0,
	SPI_TX_STATE,
	SPI_RX_STATE,
	SPI_TX_ERROR,
	SPI_RX_ERROR
}SPI_Machine_State;
/*------------------------------------*/
void soc_spi_int_thread();
void soc_spi_int_thread()
{
	tos_set_pno(SOC_I2C_TASK_PNO);
	int ss;
	ss = tos_get_state();
	switch(ss)
	{
	case SPI_IDLE_STATE:
		break;	//we should not go here
	case SPI_TX_STATE:
	{
		soc_spi_tx_len = 0;	//transmission finished
	}
		break;
	case SPI_RX_STATE:
	{
		hal_dma_read_rx_spi_device(0x0L,&soc_spi_rx_len);
	}
		break;
	case SPI_TX_ERROR:
		break;
	case SPI_RX_ERROR:
		break;
	default:
		break;
	}
}

/*------------------------------------*/
#include "0ctr.h"
#define SOC_SPI_TX_TIME_OUT		300
#define SOC_SPI_RX_TIME_OUT		500
void soc_spi_loop_thread();
void soc_spi_loop_thread()
{
	tos_set_pno(SOC_I2C_TASK_PNO);
	int ss;
	ss = tos_get_state();
	switch(ss)
	{
	case SPI_IDLE_STATE:
	{
		if(soc_spi_tx_len!=0)
		{
#if OMMO_USE_OMMO_HAL
			extern uint8_t soc_spi_cs;
extern void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
			start_spi_transfer(soc_spi_cs, soc_spi_tx_data, 0x0L, soc_spi_tx_len);
#else
			hal_dma_start_tx_spi_device(soc_spi_tx_data, soc_spi_tx_len);
#endif

			 tos_set_timer(SOC_SPI_TX_TIME_OUT);
			 tos_set_state(SPI_TX_STATE);
			 break;
		}
		if(soc_spi_cmd_len!=0)
		{
#if SPI_USE_OMMO_HAL
			extern uint8_t soc_spi_cs;
extern void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length);
			 start_spi_transfer(soc_spi_cs, soc_spi_cmd_data, soc_spi_rx_data, soc_spi_cmd_len);
#else
			 hal_dma_start_rx_spi_device(soc_spi_cmd_data, soc_spi_cmd_len);
#endif
			 tos_set_timer(SOC_SPI_RX_TIME_OUT);
			 tos_set_state(SPI_RX_STATE);
			 break;
		}
	}
		break;
	case SPI_TX_STATE:
	{
		if(soc_spi_tx_len == 0)
		{
			tos_set_state(SPI_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(!tos_check_timer())
			break;
		 tos_set_state(SPI_TX_ERROR);
	}
		break;
	case SPI_RX_STATE:
	{
		if(soc_spi_cmd_len == 0)
		{
			tos_set_state(SPI_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(soc_spi_rx_len != 0)
		{
			tos_set_state(SPI_IDLE_STATE);
			tos_clr_timer();
			break;
		}
		if(!tos_check_timer())
			break;
		 tos_set_state(SPI_RX_ERROR);
	}
		break;
	case SPI_TX_ERROR:
	{
		hal_dma_init_spi_bus();
		soc_spi_tx_len = 0;
	}
		break;
	case SPI_RX_ERROR:
	{
		hal_dma_init_spi_bus();
		soc_spi_rx_len = 0;
		soc_spi_cmd_len = 0;
	}
		break;
	default:
		break;
	}
}
/*------------------------------------*/


/*================================================================*/
/* end of task.c */
