#include <string.h>
//#include "backlash.h"
#include "grbl.h"
/*
 * backlash.c
 *
 * Created: 5/9/2019 2:08:58 AM
 *  Author: Family
 */ 

s_back_lash back_lash_compensation;
void backlash_initialize()
{
	memset(back_lash_compensation.axis_has_compensation,0,sizeof(back_lash_compensation.axis_has_compensation));
	memset(back_lash_compensation.new_comp_direction,0,sizeof(back_lash_compensation.new_comp_direction));
	memset(back_lash_compensation.last_comp_direction,0,sizeof(back_lash_compensation.last_comp_direction));
	memset(back_lash_compensation.comp_per_axis_steps,0,sizeof(back_lash_compensation.comp_per_axis_steps));
}