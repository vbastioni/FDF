/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:14:46 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/15 17:14:41 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <mlx.h>

static inline int	render_to(const t_env *e, const t_img *img, t_dir dir,
								const t_dims pos)
{
	int				i;
	t_vertex		v[2];
	int				c[2];
	int				de;
	char			*addr;

	v[0] = e->vertex[pos.y][pos.x];
	v[1] = e->vertex[pos.y + (dir > 0)][pos.x + (dir != 1)];
	c[0] = col_get(v[0], e);
	c[1] = col_get(v[1], e);
	i = 0;
	while (++i <= (e->par_inter.x))
	{
		de = ((pos.x * (e->par_inter.x + 1) + (i * (dir != 1))) * img->bpx
				+ (pos.y * (e->par_inter.y + 1) + (i * (dir > 0))) * img->sl)
				+ e->par_d.x * img->bpx + e->par_d.y * img->sl;
		addr = img->addr + de;
		*((int *)addr) = color_lerp(c[0], c[1],
									(double)i / (e->par_inter.x + 1));
	}
	return (0);
}

void				draw_par(const t_env *e)
{
	t_dims			pos;
	t_img			img;
	char			*addr;

	img.img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpx, &img.sl, &img.endian);
	img.bpx /= 8;
	pos.y = -1;
	while (++pos.y < (e->pdims.y))
	{
		pos.x = -1;
		while (++pos.x < (e->pdims.x))
		{
			addr = (img.addr + img.bpx * (e->par_d.x + pos.x
											* (e->par_inter.x + 1))
						+ img.sl * (e->par_d.y + pos.y * (e->par_inter.y + 1)));
			*((int *)addr) = col_get(e->vertex[pos.y][pos.x], e);
			((pos.x < (e->pdims.x - 1)) ? render_to(e, &img, RIG, pos) : 0);
			((pos.y < (e->pdims.y - 1)) ? render_to(e, &img, BOT, pos) : 0);
			if (pos.x < (e->pdims.x - 1) && pos.y < (e->pdims.y - 1))
				render_to(e, &img, DIA, pos);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, img.img, 0, 0);
	mlx_destroy_image(e->mlx, img.img);
}
