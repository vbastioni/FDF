/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:44:30 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/16 17:16:33 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "fdf.h"

static void		set_par_deltas(t_env *env)
{
	t_dims		d;
	t_dims		max;

	max.x = ((env->pdims.x - 1) != 0) ? env->pdims.x - 1 : 1;
	max.y = ((env->pdims.y - 1) != 0) ? env->pdims.y - 1 : 1;
	d.x = (WIN_X - env->pdims.x);
	d.y = (WIN_Y - env->pdims.y);
	env->par_inter.x = (d.x / max.x);
	env->par_inter.y = (d.y / max.y);
	if (env->par_inter.x > env->par_inter.y)
		env->par_inter.x = env->par_inter.y;
	if (env->par_inter.x < env->par_inter.y)
		env->par_inter.y = env->par_inter.x;
	env->par_d.x = (WIN_X - (env->par_inter.x * (env->pdims.x - 1)
						+ env->pdims.x)) / 2;
	env->par_d.y = (WIN_Y - (env->par_inter.y * (env->pdims.y - 1)
						+ env->pdims.y)) / 2;
}

static void		set_iso_values(t_env *env)
{
	env->zcoeff = 1.;
	env->iso_scale = 50.;
	env->iso_inter = (t_dims){10, 10};
	env->iso_angles = (t_fvector){DEF_ANG_X, DEF_ANG_Y};
	env->iso_d = (t_dims){0, 0};
}

void			env_setup(t_env *env)
{
	env->color_id = 0;
	env->rdr = NULL;
	env->render_mode = PAR;
	env->color_sets[0] = (t_dims){COL_LOW_1, COL_HIGH_1};
	env->color_sets[1] = (t_dims){COL_LOW_2, COL_HIGH_2};
	env->color_sets[2] = (t_dims){COL_LOW_3, COL_HIGH_3};
	env->color_sets[3] = (t_dims){COL_LOW_4, COL_HIGH_4};
	env->color_set_cnt = 4;
	env->iso_offset = (t_dims){0, 0};
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, WIN_NAME);
	set_par_deltas(env);
	set_iso_values(env);
	env->rdr = &draw_par;
}

void			try_get_color(int ac, char **av, t_env *env)
{
	if (ac == 4 && ft_strlen(av[2]) > 2 && ft_strncmp("0x", av[2], 2) == 0
		&& ft_strlen(av[3]) > 2 && ft_strncmp("0x", av[3], 2) == 0)
	{
		env->color_sets[4].x = ft_atoihex(av[2] + 2);
		env->color_sets[4].y = ft_atoihex(av[3] + 2);
		env->color_set_cnt = 5;
	}
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
	try_get_color(ac, av, &env);
	env.rdr(&env);
	mlx_expose_hook(env.win, &cb_expose, &env);
	mlx_key_hook(env.win, &cb_key, &env);
	mlx_hook(env.win, KEY_PRESS, KEY_PRESS_MASK, &cb_cont_key, &env);
	mlx_loop(env.mlx);
	return (free_lines(&env, env.pdims.y));
}
