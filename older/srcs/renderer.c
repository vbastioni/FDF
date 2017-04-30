/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:00:31 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 17:33:55 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <mlx.h>

#include "displays.h"
#include "renderer.h"
#include "img_data.h"
#include "defs.h"
#include "dims.h"
#include "pixel.h"

#include "math_utils.h"

#include <math.h>
#include <stdio.h>

static int	abs(int n)
{
	return (n > 0 ? n : -n);
}

static int	render_iso(const t_board *board, const t_data *data)
{
	t_img_data		*idata;
	void		*img;
	t_pixel		*px;

	img = mlx_new_image(data->mlx, W_H, W_H);
	idata = ImgData_create();
	idata->beg =
		mlx_get_data_addr(img, &idata->bpx, &idata->sl, &idata->endian);
	idata->bpx /= 8;
	px = board->pixel;
	float x = (board->pdims.x + board->pdims.y) * cos(PI / 6);
	float y = abs(board->delta.x) + abs(board->delta.y) + 
		(board->pdims.x > board->pdims.y ? board->pdims.x : board->pdims.y) *
		0.25 +
		0.5;
	printf("dims.x: %f, dims.y: %f\n", x, y);
	debug_board((t_board*)board);
	return (0);
	while (px)
	{
		px = px->next;
	}
	return (0);	
}

t_dims		get_rel_pos(t_dims pos, t_dims offset)
{
	t_dims		result;

	result.x = offset.x +
		acos(deg2rad(30)) * pos.x +
		acos(deg2rad(150)) * pos.y;
	result.y = offset.y +
   		acos(deg2rad(150)) * pos.x +
		acos(deg2rad(30)) * pos.y;
	return (result);
}

int			render_display(t_board *board, t_data *data, t_display_mode mode)
{
	if (mode == PARALLEL)
		display(board, data);
	else if (mode == ISOMETRIC)
		return (render_iso(board, data));
	return (0);
}
