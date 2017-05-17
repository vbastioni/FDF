/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:59:49 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 10:56:51 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifdef DEBUG

int			err(const char *str)
{
	ft_putstr("\e[31m");
	ft_putstr(str);
	ft_putstr("\e[0m");
	return (1);
}

#else

int			err(const char *str)
{
	(void)str;
	return (1);
}

#endif

int			free_lines(t_env *env, int cnt)
{
	int		i;

	i = 0;
	while (i < cnt)
	{
		free(env->vertex[i]);
		i++;
	}
	free(env->vertex);
	return (1);
}

int			close_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	env->win = NULL;
	on_win_close(env);
	return (1);
}

int			on_win_close(t_env *env)
{
	free_lines(env, env->pdims.y);
	exit(1);
	return (1);
}
