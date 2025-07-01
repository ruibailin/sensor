
/*------------------------------------
 * sensor_ISR.c
 * Create:  2025-07-01
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/*------------------------------------*/
int timer_isr_enable=0;
void TIMER_ISR();
void TIMER_ISR()
{
	if(timer_isr_enable == 0)
		return;
	extern void soc_i2c_loop_thread();
	soc_i2c_loop_thread();
	extern void soc_spi_loop_thread();
	soc_spi_loop_thread();
}

int i2c_isr_enable=0;
void I2C_ISR(bool success);
void I2C_ISR(bool success)
{
	if(i2c_isr_enable == 0)
		return;
	extern void soc_i2c_int_thread();
	soc_i2c_int_thread();
	i2c_isr_enable = 0;
}

int spi_isr_enable=0;
void SPI_ISR();
void SPI_ISR()
{
	if(spi_isr_enable == 0)
		return;
	extern void soc_spi_int_thread();
	soc_spi_int_thread();
	spi_isr_enable = 0;
}
/*------------------------------------*/
void start_timer();
void start_timer()
{
	timer_isr_enable = 1;
}
/*================================================================*/
/* end of sensor_ISR.c */
