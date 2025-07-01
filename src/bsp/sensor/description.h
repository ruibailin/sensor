
/*------------------------------------
 * description.h
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


#include "1imp.h"
#ifndef BSP_SENSOR_DESCRIPTION_H_
#define BSP_SENSOR_DESCRIPTION_H_
/*================================================================*/
typedef struct{
	uint32_t code;
	uint8_t  name[32];
}BSP_Sensor_Vendor_t;
typedef struct{
	uint32_t code;
	uint8_t name[32];
}BSP_Sensor_Model_t;
/*------------------------------------*/
typedef struct{
	BSP_Sensor_Vendor_t vendor;
	BSP_Sensor_Model_t model;
}BSP_Sensor_Descrip_t;
/*------------------------------------*/
extern BSP_Sensor_Descrip_t bsp_sensor_discrip_table[BSP_MAX_SENSOR_MODEL];
/*================================================================*/
#endif
/* end of description.h */
