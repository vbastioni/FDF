#include "fdf.h"

static inline t_fvector get_iso_pos(t_vector pos, const t_env *env)
{
	t_fvector           ret;
	t_fvector			ang;

	ang = env->iso_angles;
	ret.a = (cos(ang.a * TO_RAD) * pos.x)
				+ sin(ang.a * TO_RAD * pos.y
				+ 0 * pos.z);
	ret.b = (+sin(ang.a * TO_RAD) * cos(ang.b * TO_RAD)  * pos.x
				+ cos(ang.a * TO_RAD) * cos(ang.b * TO_RAD) * pos.y
				+ sin(ang.b * TO_RAD) * ((double)pos.z / (env->alts.y - env->alts.x)
										* env->zcoeff));
	ret.a *= env->iso_scale;
	ret.b *= env->iso_scale;
	return (ret);
}

static inline int		otter_range(t_fvector *a, t_fvector *b)
{
	return ((a->a < 0  && b->a < 0) || (a->b < 0 && b->b < 0) ||
		(a->a > WIN_X && b->a > WIN_X) || (a->b > WIN_Y && b->b > WIN_Y));
}

static inline int		in_window(t_fvector *pos)
{
	return (!(pos->a < 0 || pos->a > WIN_X || pos->b < 0 || pos->b > WIN_Y));
}

static void             render_to(const t_env *env, const t_img *img, 
									const t_dir dir, const t_dims pos)
{
	t_fvector           v[4];
	int                 c[4];
	t_vertex            ve[2];
	float               progress;
	char                *addr;

	ve[0] = env->vertex[pos.y][pos.x];
	ve[1] = env->vertex[pos.y + (dir > 0)][pos.x + (dir != 1)];
	v[0] = get_iso_pos(ve[0].pos, env);
	v[1] = get_iso_pos(ve[1].pos, env);
	if (otter_range(v, v + 1))
		return ;
	c[0] = col_get(ve[0], env);
	c[1] = col_get(ve[1], env);
	v[2].a = (v[1].a - v[0].a);
	v[2].b = (v[1].b - v[0].b);
	c[2] = (int)(sqrt(v[2].a * v[2].a + v[2].b * v[2].b) * LINE_PRE + 0.5);
	c[3] = -1;
	while (++c[3] < c[2])
	{
		progress = (c[3] / (float)c[2]);
		v[3].a = (v[0].a + v[2].a * progress);
		v[3].b = (v[0].b + v[2].b * progress);
		if (!in_window(v + 3))
			continue ;
		addr = (img->addr + ((int)(v[3].a + 0.5 + env->iso_delta.x)) * img->bpx
				+ ((int)(v[3].b + 0.5) - env->iso_delta.y) * img->sl);
		*((int *)addr) = color_lerp(c[0], c[1], progress);
	}
}

void					draw_iso(const t_env *env)
{
	t_dims				pos;
	t_img				img;
	t_dims				max_l;

	max_l = dims_create(env->pdims.x - 1, env->pdims.y - 1);
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