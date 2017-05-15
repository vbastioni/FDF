#ifndef ENV_H
# define ENV_H

#include <stdlib.h>
#include "dims.h"
#include "tX.h"
#include "vertex.h"
#include "renderer.h"

typedef struct	s_env
{
	t_vertex	**vertex;
	t_dims		pdims;
	t_dims		alts;
	t_dims		bounds[4];
	t_t2		wdata;
	t_mode		render_mode;
	float		iso_rot;
	t_dims		par_delta;
	t_dims		iso_delta;
	t_dims		color_sets[3];
	int			color_id;
	void		(*rdr)(const struct s_env *env);	
}				t_env;

void			setup_env(t_env *env)
{
	env->alts = dims_zero();
	env->iso_rot = 0;
	env->color_id = 0;
	env->rdr = NULL;
	env->render_mode = PAR;
}

#endif