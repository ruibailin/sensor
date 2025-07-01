
/*------------------------------------
 * task_state.h
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
/*------------------------------------*/

/*================================================================*/
/* end of task_state.h */
