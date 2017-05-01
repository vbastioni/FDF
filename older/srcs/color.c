/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:47 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 12:00:49 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"

int	color_lerp(int color_from, int color_to, float pct)
{
	if (color_from == color_to)
		return (color_from);
	unsigned char	cv[6];

	cv[0] = (color_from & 0xFF0000) >> 16;
	cv[3] = (color_to & 0xFF0000) >> 16;
	cv[1] = (color_from & 0xFF00) >> 8;
	cv[4] = (color_to & 0xFF00) >> 8;
	cv[2] = (color_from & 0xFF);
	cv[5] = (color_to & 0xFF);
	return (((cv[0] + ((UCHAR)((cv[3] - cv[0]) * pct))) << 16) |
			((cv[1] + ((UCHAR)((cv[4] - cv[1]) * pct))) << 8) |
			(cv[2] + ((UCHAR)((cv[5] - cv[2]) * pct))));
}

int	get_color(const t_vert *vert, const t_board *board)
{
	int	    neg;

	if (vert->color > -1)
	{
		/*
		ft_putstr("Alread a color: 0x");
		ft_putstr(ft_itoabase(vert->color, "0123456789ABCFED"));
		ft_putstr("\n");
		*/
		return (vert->color);
	}
	if (vert->color < 0 && vert->z == 0)
		return (COLOR_DEFAULT);
	neg = vert->z < 0;
	return (color_lerp(
				neg ? COLOR_MIN : COLOR_DEFAULT,
				neg ? COLOR_DEFAULT : COLOR_MAX,
				(float)vert->z / (neg ? board->delta.x : board->delta.y)));
}