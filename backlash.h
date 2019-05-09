#include "nuts_bolts.h"

/*
 * backlash.h
 *
 *  Author: Jeff Dill
 */ 


#ifndef BACKLASH_H_
#define BACKLASH_H_
typedef	struct  
{
	//uint8_t axis_has_compensation[N_AXIS];
	//int8_t new_comp_direction[N_AXIS];
	int8_t last_comp_direction[N_AXIS];
	uint16_t comp_per_axis_steps[N_AXIS];
}s_back_lash;
extern s_back_lash back_lash_compensation;
void backlash_initialize();
void backlash_comp(float *target, plan_line_data_t *pl_data);
#endif /* BACKLASH_H_ */