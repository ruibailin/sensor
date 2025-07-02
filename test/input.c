
/*------------------------------------
 * input.c
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

#include <stdio.h>
#include <stdlib.h>
#include "0ctr.h"
/*================================================================*/
void sys_parse_input(char cmd);
void sys_parse_input(char cmd)
{
	switch(cmd)
	{
	case '0':
	{
		printf("Test Sensor on port 0!\r\n");
		extern void start_MMC5603_data_write(void);
		start_MMC5603_data_write();
	}
		break;
	case '1':
	{
		printf("Test Sensor on port 1!\r\n");
		extern void start_MMC5983_data_write(void);
		start_MMC5983_data_write();
	}
		break;
	case '2':
	{
		extern int timer_run_enable;
		if(timer_run_enable == 0)
		{
			timer_run_enable = 1;
			printf("100ms ISR start run!\r\n");
		}
		else
		{
			timer_run_enable = 0;
			printf("100ms ISR stop run!\r\n");
		}
	}
		break;
	case '3':
	{
		printf("Test Sensor on port 3!\r\n");
		extern void start_LSM6DSM_data_write(void);
		start_LSM6DSM_data_write();
	}
		break;
	case '4':
	{
		extern int i2c_run_enable;
		if(i2c_run_enable == 0)
		{
			i2c_run_enable = 1;
			printf("I2C ISR start run!\r\n");
		}
		else
		{
			i2c_run_enable = 0;
			printf("I2C ISR stop run!\r\n");
		}
	}
		break;
	case '5':
	{
		extern int spi_run_enable;
		if(spi_run_enable == 0)
		{
			spi_run_enable = 1;
			printf("SPI ISR start run!\r\n");
		}
		else
		{
			spi_run_enable = 0;
			printf("SPI ISR stop run!\r\n");
		}
	}
		break;
	case '+':
	{
#if SYS_OS_CYGWIN
		extern unsigned int speedup;
		extern unsigned int speeddown;
		speedup++;
		speeddown=1;
		printf("Speed Up Test!%d\r\n",speedup);
#else
		extern unsigned int speedup_t;
		extern unsigned int speeddown_t;
		speedup_t++;
		speeddown_t=1;
		printf("Speed Up Test!%d\r\n",speedup_t);
#endif

	}
		break;
	case '-':
	{
#if SYS_OS_CYGWIN
		extern unsigned int speedup;
		extern unsigned int speeddown;
		speedup=1;
		speeddown++;
		printf("Speed Down Test!%d\r\n",speeddown);
#else
		extern unsigned int speedup_t;
		extern unsigned int speeddown_t;
		speedup_t=1;
		speeddown_t++;
		printf("Speed Down Test!%d\r\n",speeddown_t);
#endif
	}
		break;
	case '\n':
		break;
	default:
		break;
	}
}
/*------------------------------------*/

/*================================================================*/
/* end of input.c */
