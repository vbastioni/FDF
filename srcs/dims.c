/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dims.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:33:01 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 09:54:09 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dims.h"

void	Dims_set(t_dims *dims, int x, int y)
{
	if (!dims)
		return ;
	dims->x = x;
	dims->y = y;
}

t_dims	dims_zero()
{
	t_dims	dms;

	dms.x = 0;
	dms.y = 0;
	return (dms);
}
