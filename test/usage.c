
/*------------------------------------
 * usage.c
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


/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------*/
void sys_print_usage();
void sys_print_usage()
{
	printf("Sensor Test Usage:\r\n");
	printf("Input 0: Test Port 0(MMC5603)\r\n");
	printf("Input 1: Test Port 1(MMC5603)\r\n");
	printf("Input 3: Test Port 3(LSM6DSM)\r\n");
	printf("Input 2: Toggle ISR(Timer)\r\n");
	printf("Input 4: Toggle ISR(I2C)\r\n");
	printf("Input 5: Toggle ISR(SPI)\r\n");
	printf("Input +: Make system run fast\r\n");
	printf("Input -: Make system run slow\r\n");
	printf("Input q: Quit test\r\n");
}
/*================================================================*/
/* end of usage.c */
