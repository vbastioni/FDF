#include <math.h>

#include "renderer.h"
#include "defs.h"
#include "vector.h"
#include "color.h"

# define Z_COEFF (0.20)
# define ANG (30)
# define OPP_ANG (180 - ANG)
# define LINE_PRE 10

static inline double	d2r(double deg)
{
	return (deg * PI / 180.0);
}

static inline double	abs(double f)
{
	return (f < 0 ? -f : f);
}

static t_fvector	get_iso_pos(t_vector pos, float scale)
{
	t_fvector		ret;

	ret.a = -(pos.x * abs(cos(d2r(ANG))) - (pos.y * abs(cos(d2r(OPP_ANG))))) * scale;
	ret.b = -(pos.z * Z_COEFF + pos.x * sin(d2r(ANG)) + pos.y * sin(d2r(OPP_ANG))) * scale;
	return (ret);
} 

static inline void 		set_delta(t_dims *delta, float *scale, 
									const t_board *board)
{
	t_dims				obj_sz;
	t_dims				scales;

	obj_sz.x = (int)((board->pdims.x + board->pdims.y)
					* abs(cos(d2r(ANG))) + 0.5);
	obj_sz.y = (int)((board->alts.y + abs(board->alts.x)) * Z_COEFF
					+ (board->pdims.x + board->pdims.y) * sin(d2r(ANG)));
	scales.x = BOARD_MAX_WIDTH / obj_sz.x;
	scales.y = BOARD_MAX_HEIGHT / obj_sz.y;
	*scale = scales.x < scales.y ? scales.x : scales.y;
    delta->x = (board->pdims.x * (abs(cos(d2r(ANG)))) * *scale
				- ((board->pdims.x + board->pdims.y) * abs(cos(d2r(ANG)))
					* *scale / 2) - BOARD_MAX_WIDTH / 2);
	delta->y = BOARD_MAX_HEIGHT + board->alts.x * Z_COEFF * *scale;
}

/*
static void			line_to(const t_dims pos, const t_dir dir,
							const t_board *board, const t_imgdata *iptr, 
							const t_dims *delta_dim, const float scale)
{
	t_fvector			v[4];
	t_vertex			ve[2];
	int					c[4];
	float 				progress;
	char 				*addr;

	ve[0] = board->vertex[pos.y][pos.x];
	ve[1] = board->vertex[pos.y + dir > 0][pos.x + dir != 1];
	v[0] = get_iso_pos(ve[0].pos, scale);
	v[1] = get_iso_pos(ve[1].pos, scale);
	c[0] = ve[0].color != -1 ? ve[0].color : col_get(ve[0].pos.z, board->alts);
	c[1] = ve[1].color != -1 ? ve[1].color : col_get(ve[1].pos.z, board->alts);
	v[2].a = (v[1].a - v[0].a);
	v[2].b = (v[1].b - v[0].b);
	c[2] = (int)(sqrt(v[2].a * v[2].a + v[2].b * v[2].b) * LINE_PRE + 0.5);
	c[3] = 0;
	while (c[3] < c[2])
	{
		progress = (c[3] / (float)c[2]);
		v[3].a = (v[0].a + (v[1].a - v[0].a) * progress);
		v[3].b = (v[0].b + (v[1].b - v[0].b) * progress);
		addr = (iptr->addr + ((int)(v[3].a + 0.5 + delta_dim->x)) * iptr->bpx
					+ ((int)(v[3].b + 0.5 + delta_dim->y)) * iptr->sl);
		*((int *)addr) = (color_lerp(c[0], c[1], progress));
		c[3]++;
	}
}
*/

static void			line_to(const t_vertex f, const t_vertex t,
								const t_board *board, const t_imgdata *iptr, 
								const t_dims *delta_dim, const float scale)
{
	t_fvector			v[4];
	int					c[4];
	float 				progress;
	char 				*addr;

	v[0] = get_iso_pos(f.pos, scale);
	v[1] = get_iso_pos(t.pos, scale);
	c[0] = f.color != -1 ? f.color : col_get(f.pos.z, board->alts);
	c[1] = t.color != -1 ? t.color : col_get(t.pos.z, board->alts);
	v[2].a = (v[1].a - v[0].a);
	v[2].b = (v[1].b - v[0].b);
	c[2] = (int)(sqrt(v[2].a * v[2].a + v[2].b * v[2].b) * LINE_PRE + 0.5);
	c[3] = 0;
	while (c[3] < c[2])
	{
		progress = (c[3] / (float)c[2]);
		v[3].a = (v[0].a + (v[1].a - v[0].a) * progress);
		v[3].b = (v[0].b + (v[1].b - v[0].b) * progress);
		addr = (iptr->addr + ((int)(v[3].a + 0.5 + delta_dim->x)) * iptr->bpx
					+ ((int)(v[3].b + 0.5 + delta_dim->y)) * iptr->sl);
		*((int *)addr) = (color_lerp(c[0], c[1], progress));
		c[3]++;
	}
}


void					render_iso(const t_board *board, const t_imgdata *iptr,
									t_dims *delta)
{
	const t_dims		max = {.x = board->pdims.x - 1, 
								.y = board->pdims.y - 1};
    float				scale;
    t_dims				its;
	
	set_delta(delta, &scale, board);
	its = dims_create(max.x, max.y);
	while (--its.y >= 0)
	{
		while (--its.x >= 0)
		{
			line_to(board->vertex[its.y][its.x],
					board->vertex[its.y][its.x + 1], board, iptr, delta, scale);
			line_to(board->vertex[its.y][its.x],
					board->vertex[its.y + 1][its.x], board, iptr, delta, scale);
			line_to(board->vertex[its.y][its.x],
					board->vertex[its.y + 1][its.x + 1],
					board, iptr, delta, scale);
					/*
            line_to(its, RIG, board, iptr, delta, scale);
			line_to(its, BOT, board, iptr, delta, scale);
			line_to(its, DIA, board, iptr, delta, scale);
        */
		}
		its.x = max.x;
	}
}