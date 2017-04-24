/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:54:56 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 16:26:28 by vbastion         ###   ########.fr       */
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

char	*get_addr(t_pixel *px, t_img_data *data, const t_board *board)
{
	int		inter;

	inter = board->inter.x < board->inter.y ? board->inter.x : board->inter.y;
	return (data->beg +
			board->padding.y * data->sl +
			px->vert->y * (data->sl * inter) +
			board->padding.x * data->bpx +
			px->vert->x * (data->bpx * inter));
}

void	render(int color, char *addr)
{
	*(addr + 0) = color & 0xFF;
	*(addr + 1) = (color & 0xFF00) >> 8;
	*(addr + 2) = (color & 0xFF0000) >> 16;
}

void	render_to_next(t_pixel *px, t_img_data *data, t_board * board,
		int inter)
{
	int			color_curr;
	int			color_next;
	int			i;
	char		*beg;

	if (!(px->next && px->next->vert->x != 0))
		return ;
	beg = get_addr(px, data, board);
	color_curr = get_color(px->vert, board);
	color_next = get_color(px->next->vert, board);
	i = 1;
	while (i < inter)
	{
		render(color_lerp(color_curr, color_next, (float)i / board->inter.x),
				get_addr(px, data, board) + i * data->bpx);
		i++;
	}
}

void	render_to_bottom(t_pixel *px, t_img_data *data, t_board *board,
		int inter)
{
	int			color_curr;
	int			color_next;
	t_pixel		*down;
	int			i;
	char		*beg;

	if (!((px->vert->y + 1) < board->pdims.y))
		return ;
	beg = get_addr(px, data, board);
	color_curr = get_color(px->vert, board);
	down = px;
	while (down)
	{
		down = down->next;
		if (down->vert->x == px->vert->x && down->vert->y == (px->vert->y + 1))
			break;
	}
	color_next = get_color(down->vert, board);
	i = 1;
	while (i < inter)
	{
		render(color_lerp(color_curr, color_next, (float)i / board->inter.x),
				get_addr(px, data, board) + i * data->sl);
		i++;
	}
}

void	display(t_board	*board, t_data *data)
{
	void		*img;
	t_img_data	*idata;
	t_pixel		*px;
	int			inter;

	px = board->pixel;
	img = mlx_new_image(data->mlx, 400, 400);
	idata = ImgData_create();
	idata->beg = 
		mlx_get_data_addr(img, &idata->bpx, &idata->sl, &idata->endian);
	idata->bpx /= 8;
	board_set_dims(board);
	inter = board->inter.x < board->inter.y ? board->inter.x : board->inter.y;
	while (px)
	{
		render(get_color(px->vert, board), get_addr(px, idata, board));
		render_to_next(px, idata, board, inter);
		render_to_bottom(px, idata, board, inter);
		px = px->next;
	}
	mlx_put_image_to_window (data->mlx, data->win, img, 0, 0);
}
