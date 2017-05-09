#include <mlx.h>

#include "fdf.h"

static void		get_par_deltas(t_env *env)
{
	t_dims		d;

	d.x = (WIN_X - env->pdims.x);
	env->iso_inter.x = (d.x / (env->pdims.x - 1));
	d.y = (WIN_Y - env->pdims.y);
	env->iso_inter.y = (d.y / (env->pdims.y - 1));
	if (env->iso_inter.x > env->iso_inter.y)
		env->iso_inter.x = env->iso_inter.y;
	if (env->iso_inter.x < env->iso_inter.y)
		env->iso_inter.y = env->iso_inter.x;
	env->par_delta.x = (WIN_X - (env->iso_inter.x * (env->pdims.x - 1)
						+ env->pdims.x)) / 2;
	env->par_delta.y = (WIN_Y - (env->iso_inter.y * (env->pdims.y - 1)
						+ env->pdims.y)) / 2;
}

static void		get_iso_deltas(const t_env *env)
{
	//
	(void)env;
}

int				main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (1);
	env_setup(&env);
	if (!preparse_data(av[1], &env))
		return (1);
	if (!parse_data(av[1], &env))
		return (1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, WIN_NAME);
	get_par_deltas(&env);
	get_iso_deltas(&env);
	mlx_expose_hook(env.win, &cb_expose, &env);
	mlx_key_hook(env.win, &cb_key, &env);
	mlx_loop(env.mlx);
	return (0);
}