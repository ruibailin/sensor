
/*------------------------------------
 * description.c
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
/*================================================================*/
#include "description.h"
BSP_Sensor_Descrip_t bsp_sensor_discrip_table[BSP_MAX_SENSOR_MODEL]={
		{{0,{}},{6,{}}},
		{{1,{}},{5603,{}}},
		{{1,{}},{5983,{}}},
};
/*------------------------------------*/
void *bsp_get_sensor_discrip(uint32_t model_code);
void *bsp_get_sensor_discrip(uint32_t model_code)
{
	int i;
	for(i=0;i<BSP_MAX_SENSOR_MODEL;i++)
	{
		if(bsp_sensor_discrip_table[i].model.code == model_code)
			return &bsp_sensor_discrip_table[i];
	}
	return 0x0L;
}
/*================================================================*/
/* end of description.c */
