#include <mlx.h>

#include "fdf.h"

static void		set_par_deltas(t_env *env)
{
	t_dims		d;

	d.x = (WIN_X - env->pdims.x);
	d.y = (WIN_Y - env->pdims.y);
	env->par_inter.x = (d.x / (env->pdims.x - 1));
	env->par_inter.y = (d.y / (env->pdims.y - 1));
	if (env->par_inter.x > env->par_inter.y)
		env->par_inter.x = env->par_inter.y;
	if (env->par_inter.x < env->par_inter.y)
		env->par_inter.y = env->par_inter.x;
	env->par_delta.x = (WIN_X - (env->par_inter.x * (env->pdims.x - 1)
						+ env->pdims.x)) / 2;
	env->par_delta.y = (WIN_Y - (env->par_inter.y * (env->pdims.y - 1)
						+ env->pdims.y)) / 2;
}

static void		set_iso_deltas(t_env *env)
{
	float		max;

	max = env->pdims.x < env->pdims.y ? env->pdims.y : env->pdims.x;
	max = max * cos(ANG * PI / 180.0) * 2;
	env->iso_scale = WIN_X / max;
}

void			env_setup(t_env *env)
{
	env->color_id = 0;
	env->rdr = NULL;
	env->angle = 90;
	env->render_mode = PAR;
	env->color_sets[0] = dims_create(COL_LOW_1, COL_HIGH_1);
	env->color_sets[1] = dims_create(COL_LOW_2, COL_HIGH_2);
	env->color_sets[2] = dims_create(COL_LOW_3, COL_HIGH_3);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, WIN_NAME);
	set_par_deltas(env);
	set_iso_deltas(env);
	env->rdr = &draw_par;
}

int				main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (1);
	if (!preparse_data(av[1], &env))
		return (1);
	if (!parse_data(av[1], &env))
		return (1);
	env_setup(&env);
	env.rdr(&env);
	mlx_expose_hook(env.win, &cb_expose, &env);
	mlx_key_hook(env.win, &cb_key, &env);
	mlx_loop(env.mlx);
	return (0);
}