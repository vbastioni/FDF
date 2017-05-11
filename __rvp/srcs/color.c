#include "fdf.h"

int  col_get(t_vertex v, const t_env *env)
{
    float pct;
    
    pct = (float)(v.pos.z - env->alts.x) / (float)(env->alts.y - env->alts.x);
	int c = (color_lerp(env->color_sets[env->color_id].x,
						env->color_sets[env->color_id].y, pct));
    return (c);
}

int	color_lerp(int color_from, int color_to, double pct)
{
	t_color f;
	t_color t;
	t_color r;

	f.color = color_from;
	t.color = color_to;
	r.color = 0x0;
	r.c[0] = f.c[0] + (t.c[0] - f.c[0]) * pct;
	r.c[1] = f.c[1] + (t.c[1] - f.c[1]) * pct;
	r.c[2] = f.c[2] + (t.c[2] - f.c[2]) * pct;
	return (r.color);
}