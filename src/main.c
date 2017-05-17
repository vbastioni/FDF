/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:44:30 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 16:52:39 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "fdf.h"

static void		set_iso_values(t_env *env)
{
	env->zcoeff = 1.;
	env->iso_scale = DEF_ZOOM;
	env->iso_inter = (t_dims){10, 10};
	env->iso_angles = (t_fvector){DEF_ANG_X, DEF_ANG_Y};
	env->iso_d = (t_dims){0, 0};
}

static int		env_setup(t_env *env)
{
	env->color_id = 0;
	env->color_sets[0] = (t_dims){COL_LOW_1, COL_HIGH_1};
	env->color_sets[1] = (t_dims){COL_LOW_2, COL_HIGH_2};
	env->color_sets[2] = (t_dims){COL_LOW_3, COL_HIGH_3};
	env->color_sets[3] = (t_dims){COL_LOW_4, COL_HIGH_4};
	env->color_set_cnt = 4;
	env->iso_offset = (t_dims){0, 0};
	if (!(env->mlx = mlx_init()))
		return (0 * close_window(env) * err("Could not init mlx\n"));
	if (!(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, WIN_NAME)))
		return (0 * close_window(env) * err("Could not create new window\n"));
	set_iso_values(env);
	env->rdr = &draw_iso;
	return (1);
}

static void		try_get_color(int ac, char **av, t_env *env)
{
	if (ac == 4 && ft_strlen(av[2]) > 2 && ft_strncmp("0x", av[2], 2) == 0
		&& ft_strlen(av[3]) > 2 && ft_strncmp("0x", av[3], 2) == 0)
	{
		env->color_sets[4].x = ft_atoihex(av[2] + 2);
		env->color_sets[4].y = ft_atoihex(av[3] + 2);
		env->color_set_cnt = 5;
	}
}

static int		good_args(int ac, char **av)
{
	int			i;

	i = (ac == 2 || (ac == 4 && ft_strncmp(av[2], "0x", 2) == 0
						&& ft_strncmp(av[3], "0x", 2) == 0));
	if (i)
		return (1);
	ft_putstr("Usage: ");
	ft_putstr(av[0]);
	ft_putstr(" <filename> [<color hex #1> <color hex #2>]\n");
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;

	if (!good_args(ac, av))
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
	mlx_hook(env.win, DESTROY_NOTIFY, NO_EVENT_MASK, &on_win_close, &env);
	mlx_loop(env.mlx);
	return (0);
}
