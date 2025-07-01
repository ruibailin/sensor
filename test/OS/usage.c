
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

#include "..\0ctr.h"
#if SYS_TEST_IN_OS
/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------*/
void print_usage();
void print_usage()
{
	printf("Sensor Test Usage:\r\n");
	printf("Input 1: Test Port 1(MMC5603)\r\n");
	printf("Input 2: Test Port 2(MMC5603)\r\n");
	printf("Input 4: Test Port 4(LSM6DSM)\r\n");
	printf("Input +: Make system run fast\r\n");
	printf("Input -: Make system run slow\r\n");
}
/*================================================================*/
#endif
/* end of usage.c */
