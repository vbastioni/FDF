#include "fdf.h"

#include <mlx.h>

static inline void	render_to(const t_env *env, const t_img *img, t_dir dir,
								const t_dims pos)
{
	int				i;
	t_vertex		v[2];
	int				c[2];
	int				de;
	char			*addr;

	if ((pos.x + (dir != 1)) == env->pdims.x || env->iso_inter.x == 0
		|| (pos.y + (dir > 0)) == env->pdims.y || env->iso_inter.y == 0)
		return ;
	v[0] = env->vertex[pos.y][pos.x];
	v[1] = env->vertex[pos.y + (dir > 0)][pos.x + (dir != 1)];
	c[0] = col_get(v[0], env->alts);
	c[1] = col_get(v[1], env->alts);
	i = 0;
	while (++i <= env->iso_inter.x)
	{
		de = ((pos.x * (env->iso_inter.x + 1) + (i * (dir != 1))) * img->bpx
				+ (pos.y * (env->iso_inter.y + 1) + (i * (dir > 0))) * img->sl)
				+ env->par_delta.x * img->bpx + env->par_delta.y * img->sl;
		addr = img->addr + de;
		*((int *)addr) = color_lerp(c[0], c[1],
									(double)i / (env->iso_inter.x + 1));
	}
}

void				draw_par(const t_env *env)
{
	t_dims			pos;
	t_img			img;

	img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpx, &img.sl, &img.endian);
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
	// put image to screen.
	mlx_destroy_image(env->mlx, img.img);
}