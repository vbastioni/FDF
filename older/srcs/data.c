/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:05:58 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:32:56 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"

t_data	*create_data(void *win, void *mlx)
{
	t_data	*ret;

	if (!(ret = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	ret->win = win;
	ret->mlx = mlx;
	return (ret);
}
