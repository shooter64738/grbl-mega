#include <string.h>
//#include "backlash.h"
#include "grbl.h"
/*
 * backlash.c
 *
 *  Author: Jeff Dill
 */ 

s_back_lash back_lash_compensation;
void backlash_initialize()
{
	//memset(back_lash_compensation.axis_has_compensation,0,sizeof(back_lash_compensation.axis_has_compensation));
	//memset(back_lash_compensation.new_comp_direction,0,sizeof(back_lash_compensation.new_comp_direction));
	memset(back_lash_compensation.last_comp_direction,0,sizeof(back_lash_compensation.last_comp_direction));
	memset(back_lash_compensation.comp_per_axis_steps,0,sizeof(back_lash_compensation.comp_per_axis_steps));
}

void backlash_comp(float *target, plan_line_data_t *pl_data)
{
	int32_t target_steps[N_AXIS];
	int32_t *position_steps;
	
	if (pl_data->condition & PL_COND_FLAG_SYSTEM_MOTION)
	{
		#ifdef COREXY
		position_steps[X_AXIS] = system_convert_corexy_to_x_axis_steps(sys_position);
		position_steps[Y_AXIS] = system_convert_corexy_to_y_axis_steps(sys_position);
		position_steps[Z_AXIS] = sys_position[Z_AXIS];
		#else
		memcpy(position_steps, sys_position, sizeof(sys_position));
		#endif
	}
	else
	{
		position_steps = plan_get_position();
		//memcpy(position_steps, pl.position, sizeof(pl.position));
	}
	
	uint8_t idx=0;
	uint8_t needs_comp = 0;
	
	for (idx = 0;idx<N_AXIS;idx++)
	{
		back_lash_compensation.comp_per_axis_steps[idx] = 0;
		target_steps[idx] = lround(target[idx] * settings.steps_per_mm[idx]);
		int32_t step_diff=(target_steps[idx] - position_steps[idx]);
		step_diff = step_diff>0?1:(step_diff<0?-1:0);
		if (back_lash_compensation.last_comp_direction[idx]!=0 && step_diff!=0
		&& (back_lash_compensation.last_comp_direction[idx] !=step_diff))
		{
			back_lash_compensation.comp_per_axis_steps[idx]	=
			(settings.backlash_per_axis[idx]*settings.steps_per_mm[idx]);

			//I dont think these will be needed, but they are available.
			//back_lash_compensation.new_comp_direction[idx] = step_diff;
			//back_lash_compensation.axis_has_compensation[idx] = 1;
		}
	}
}