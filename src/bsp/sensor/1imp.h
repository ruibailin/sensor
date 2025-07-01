
/*------------------------------------
 * 1imp.h
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


#ifndef BSP_SENSOR_1IMP_H_
#define BSP_SENSOR_1IMP_H_
/*================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------*/
#include "..\msg_ring_buf.h"
/*------------------------------------*/
#define BSP_MAX_SENSOR_PORT		5
#define BSP_MAX_SENSOR_MODEL	3
/*------------------------------------*/
#define BSP_READ_SENSOR_INTERVAL	1000
#define BSP_WAIT_SENSOR_MAX_TIME	6000	//3 seconds
/*------------------------------------*/
typedef enum{
	BSP_SSR_INIT = 0,
	BSP_SSR_ONLINE,
	BSP_SSR_ONLINE_READ,
	BSP_SSR_ONLINE_WRITE,
	BSP_SSR_OFFLINE,
	BSP_SSR_OFFLINE_TEST,
}SPI_Machine_State;
/*================================================================*/
#endif
/* end of 1imp.h */
