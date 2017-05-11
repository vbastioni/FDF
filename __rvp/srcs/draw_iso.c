#include "fdf.h"

static inline double    d2r(double deg)
{
	return (deg * PI / 180.0);
}

static inline double	l_abs(double f)
{
	return (f < 0 ? -f : f);
}

static inline t_fvector get_iso_pos(t_vector pos, const t_env *env)
{
	t_fvector           ret;
	t_fvector           tmp;

	tmp.a = (-(pos.x * l_abs(cos(d2r(ANG)))
				- (pos.y * l_abs(cos(d2r(OPP_ANG))))) * env->iso_scale);
	tmp.b = (-(-pos.z * Z_COEFF + pos.x * sin(d2r(ANG))
				+ pos.y * sin(d2r(OPP_ANG))) * env->iso_scale);
    if (env->angle > 0)
	{
		ret.a = tmp.a * cos(PI) + tmp.b * -sin(PI);
		ret.b = tmp.a * sin(PI) + tmp.b * cos(PI);
		return (ret);
	}
	return (tmp);
}

static void             render_to(const t_env *env, const t_img *img, 
									const t_dir dir, const t_dims pos)
{
	t_fvector           v[4];
	int                 c[4];
	t_vertex            ve[2];
	float               progress;
	char                *addr;

    if ((pos.y + (dir > 0)) >= env->pdims.y
		|| (pos.x + (dir != 1)) >= env->pdims.x)
		return ;
	ve[0] = env->vertex[pos.y][pos.x];
	ve[1] = env->vertex[pos.y + (dir > 0)][pos.x + (dir != 1)];
	v[0] = get_iso_pos(ve[0].pos, env);
	v[1] = get_iso_pos(ve[1].pos, env);
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
        int delta = ((int)(v[3].a + 0.5)) * img->bpx
				+ ((int)(v[3].b + 0.5)) * img->sl;
		addr = (img->addr + delta);
		int color = color_lerp(c[0], c[1], progress);
		*((int *)addr) = color;
	}
}

void					draw_iso(const t_env *env)
{
	t_dims				pos;
	t_img				img;

	img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpx, &img.sl, &img.endian);
	img.bpx /= 8;
	pos.y = -1;
	while (++pos.y < env->pdims.y)
	{
		pos.x = -1;
		while (++pos.x < env->pdims.x)
		{
				render_to(env, &img, RIG, pos);
				render_to(env, &img, BOT, pos);
				render_to(env, &img, DIA, pos);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_destroy_image(env->mlx, img.img);
}