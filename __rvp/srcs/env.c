#include "fdf.h"

void			env_setup(t_env *env)
{
	env->alts = dims_zero();
	env->iso_rot = 0;
	env->color_id = 0;
	env->rdr = NULL;
	env->render_mode = PAR;
}