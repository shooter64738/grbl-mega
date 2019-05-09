#include "nuts_bolts.h"

/*
 * backlash.h
 *
 * Created: 5/9/2019 2:09:17 AM
 *  Author: Family
 */ 


#ifndef BACKLASH_H_
#define BACKLASH_H_
typedef	struct  
{
	uint8_t axis_has_compensation[N_AXIS];
	int8_t new_comp_direction[N_AXIS];
	int8_t last_comp_direction[N_AXIS];
	uint16_t comp_per_axis_steps[N_AXIS];
}s_back_lash;
extern s_back_lash back_lash_compensation;
void backlash_initialize();



#endif /* BACKLASH_H_ */