/*
 * 1imp.h
 *
 *  Created on: Jan 24, 2025
 *      Author: stever
 */

#ifndef TOS_1IMP_H_
#define TOS_1IMP_H_
/*================================================================*/
#include "..\tos.h"
#define	TOS_MAX_PAT_TYPE	2
#define	TOS_MAX_PAT_NUM		TOS_MAX_PNO
/*------------------------------------*/
#include <stdio.h>
#include "0ctr.h"
#if TOS_DEBUG
#define tos_print(x...)  	printf(x);
#define tos_debug(x...)  	printf(x);
#define tos_alarm(x...)   	printf(x);
#define tos_panic(x...)		printf(x);
#else
#define tos_print(x...)
#define tos_debug(x...)
#define tos_alarm(x...)
#define tos_panic(x...)
#endif
/*------------------------------------*/
/*================================================================*/
#endif /* TOS_1IMP_H_ */
