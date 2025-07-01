
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
#include "task_state.h"
/*------------------------------------*/
extern void (*device_inserted_removed_callback)(uint8_t port_num, bool device_inserted);
extern void (*data_read_callback)(uint8_t port_num, uint8_t *data);
/*------------------------------------*/
#define BSP_MAX_DATA_LENGTH			24
/*================================================================*/
#endif
/* end of 1imp.h */
