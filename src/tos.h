
/*------------------------------------
 * tos.h
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



#ifndef SRC_TOS_H_
#define SRC_TOS_H_
/*================================================================*/
#include ".\TinyOS\user.h"
/*------------------------------------*/
#include ".\TinyOS\kernel.h"
/*------------------------------------*/
//Register all process number here
typedef	enum{
	SOC_I2C_TASK_PNO,
	SOC_SPI_TASK_PNO,
	BSP_SSR_START_PNO,
	BSP_SSR_SPI_PNO = BSP_SSR_START_PNO+1,
	BSP_SSR_END_PNO = BSP_SSR_SPI_PNO+4,
	TOS_MAX_PNO
}TOS_ALL_PNO;
/*================================================================*/
#endif
/* end of tos.h */
