/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:56:06 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/15 14:49:55 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fvector				get_iso_pos(t_vector *pos, const t_env *env)
{
	t_fvector			ret;
	t_fvector			ang;

	ang.a = env->iso_angles.a;
	ang.b = env->iso_angles.b;
	ret.a = cos(ang.a * TO_RAD) * pos->x - sin(ang.a * TO_RAD) * pos->y;
	ret.b = sin(ang.a * TO_RAD) * cos(ang.b * TO_RAD) * pos->x
					+ cos(ang.a * TO_RAD) * cos(ang.b * TO_RAD) * pos->y
					- sin(ang.b * TO_RAD) * ((double)pos->z
												/ (env->alts.y - env->alts.x)
												* env->zcoeff);
	ret.a *= env->iso_scale;
	ret.b *= env->iso_scale;
	return (ret);
}

static inline int		outer_range(t_fvector *a, t_fvector *b)
{
	return ((a->a < 0 && b->a < 0) || (a->b < 0 && b->b < 0)
			|| (a->a > WIN_X && b->a > WIN_X)
			|| (a->b > WIN_Y && b->b > WIN_Y));
}

static void				draw_from_to(const t_env *env, const t_img *img,
										t_fvector *vecs, t_vertex *verts)
{
	int					colors[2];
	int					iter;
	int					i;
	float				progress;
	char				*addr;

	colors[0] = col_get(verts[0], env);
	colors[1] = col_get(verts[1], env);
	vecs[2].a = (vecs[1].a - vecs[0].a);
	vecs[2].b = (vecs[1].b - vecs[0].b);
	iter = (int)(sqrt(vecs[2].a * vecs[2].a + vecs[2].b * vecs[2].b) + 0.5);
	i = -1;
	while (++i < iter)
	{
		progress = (i / (float)iter);
		vecs[3].a = (vecs[0].a + vecs[2].a * progress);
		vecs[3].b = (vecs[0].b + vecs[2].b * progress);
		if ((vecs + 3)->a < 0 || (vecs + 3)->a > (WIN_X - 2)
			|| (vecs + 3)->b < 0 || (vecs + 3)->b > (WIN_Y - 2))
			continue ;
		addr = (img->addr + ((int)(vecs[3].a + 0.5)) * img->bpx
				+ ((int)(vecs[3].b + 0.5)) * img->sl);
		*((int *)addr) = color_lerp(colors[0], colors[1], progress);
	}
}

static void				render_to(const t_env *env, const t_img *img,
									const t_dir dir, const t_dims pos)
{
	t_fvector			v[4];
	t_vertex			ve[2];

	ve[0] = env->vertex[pos.y][pos.x];
	ve[1] = env->vertex[pos.y + (dir > 0)][pos.x + (dir != 1)];
	v[0] = get_iso_pos(&ve->pos, env);
	v[0].a += WIN_X / 2 - env->iso_d.x + env->iso_offset.x;
	v[0].b += WIN_Y / 2 - env->iso_d.y + env->iso_offset.y;
	v[1] = get_iso_pos(&((ve + 1)->pos), env);
	v[1].a += WIN_X / 2 - env->iso_d.x + env->iso_offset.x;
	v[1].b += WIN_Y / 2 - env->iso_d.y + env->iso_offset.y;
	if (outer_range(v, v + 1))
		return ;
	draw_from_to(env, img, v, ve);
}

void					draw_iso(const t_env *env)
{
	t_dims				pos;
	t_img				img;
	t_dims				max_l;

	set_env_iso_delta((t_env *)env);
	max_l = (t_dims){env->pdims.x - 1, env->pdims.y - 1};
	img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpx, &img.sl, &img.endian);
	img.bpx /= 8;
	pos.y = -1;
	while (++pos.y < env->pdims.y)
	{
		pos.x = -1;
		while (++pos.x < env->pdims.x)
		{
			if (pos.x < max_l.x)
				render_to(env, &img, RIG, pos);
			if (pos.y < max_l.y)
				render_to(env, &img, BOT, pos);
			if (pos.x < max_l.x && pos.y < max_l.y)
				render_to(env, &img, DIA, pos);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_destroy_image(env->mlx, img.img);
}
