/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:54:56 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:18:28 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "libft.h"

#include "board.h"
#include "parsing.h"
#include "data.h"
#include "displays.h"
#include "color.h"
#include "vertice.h"

#include "dims.h"
#include "img_data.h"

char	*get_addr(t_pixel *px, t_img_data *data, t_dims padding, int inter)
{
	return (data->beg +
			padding.y * data->sl +
			px->vert->y * (data->sl * inter) +
			padding.x * data->bpx +
			px->vert->x * (data->bpx * inter));
}

int	get_color(const t_vert *vert, const t_board *board)
{
	int	    neg;

	if (vert->color > -1)
		return (vert->color);
	if (vert->color < 0 && vert->z == 0)
		return (COLOR_DEFAULT);
	neg = vert->z < 0;
	return (color_lerp(
				neg ? COLOR_MIN : COLOR_DEFAULT,
				neg ? COLOR_DEFAULT : COLOR_MAX,
				(float)vert->z / (neg ? board->delta.x : board->delta.y)));
}

void	render(int color, char *addr)
{
	*(addr + 0) = color & 0xFF;
	*(addr + 1) = (color & 0xFF00) >> 8;
	*(addr + 2) = (color & 0xFF0000) >> 16;
}

t_dims	set_inter(const t_board *board)
{
	t_dims  ret;

	ret.x = (400 - board->pdims.x) / (board->pdims.x - 1);
	ret.y = (400 - board->pdims.y) / (board->pdims.y - 1);
	return (ret);
}

t_dims	set_padding(const t_dims inter, const t_board *board)
{
	t_dims  ret;

	ret.x = (400 - inter.x * (board->pdims.x - 1)) / 2;
	ret.y = (400 - inter.y * (board->pdims.y - 1 )) /2;
	return (ret);
}

void	display(t_board	*board, t_data *data)
{
	void	*img;
	t_img_data	*idata;
	t_pixel	*px;
	t_dims	padding;
	t_dims	inter;

	px = board->pixel;
	img = mlx_new_image(data->mlx, 400, 400);
	idata = ImgData_create();
	idata->beg = 
		mlx_get_data_addr(img, &idata->bpx, &idata->sl, &idata->endian);
	idata->bpx /= 8;
	inter = set_inter(board);
	padding = set_padding(inter, board);
	while (px)
	{
		render(get_color(px->vert, board),
				get_addr(px, idata, padding, inter.x < inter.y ? inter.x : inter.y));
		px = px->next;
	}
	mlx_put_image_to_window (data->mlx, data->win, img, 0, 0);
}
