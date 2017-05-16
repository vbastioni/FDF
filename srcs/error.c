/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:59:49 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/15 14:44:06 by vbastion         ###   ########.fr       */
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
	while (i <= cnt)
	{
		free(env->vertex[i]);
		i++;
	}
	free(env->vertex);
	return (0);
}
