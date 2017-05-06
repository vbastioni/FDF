#include <stdio.h>//

#include <math.h>

#include "renderer.h"
#include "defs.h"
#include "vector.h"
#include "color.h"

static void 		set_delta(t_dims *delta, t_board *board)
{
	t_dims      	d;
	t_fvector   	sz_vec;

	d = board->pdims;
	sz_vec.a = (((d.x < d.y) ? d.y : d.y) * 0.25f + 0.5f
				+ board->alts.x + board->alts.y);
	sz_vec.b = (d.x + d.y) * cos(PI / 6.0f);
	(void)delta;
}

# define DELTA_POS 450
# define Z_COEFF 0.11

static t_fvector	get_iso_pos(t_vector pos, int max)
{
	t_fvector		ret;

	(void)max;
	ret.a = -(pos.x * (cos(PI / 6)) - (pos.y * cos(PI / 6)));
	ret.b = -((pos.z * Z_COEFF + ((pos.x + pos.y) * 0.5)));
	return (ret);
} 


void				line_to(t_vector f, t_vector t, t_board *board,
							t_imgdata *iptr, int max_h)
{
	t_fvector		p[2];
	t_fvector		delta;
	t_fvector		tmp;
	int				dist;
	int				i;
	float 			progress;

	p[0] = get_iso_pos(f, max_h);
	p[1] = get_iso_pos(t, max_h);
	delta.a = (p[1].a - p[0].a);
	delta.b = (p[1].b - p[0].b);
	dist = (int)(sqrt(delta.a * delta.a + delta.b * delta.b) * 10 + 0.5);
	for (i = (dist - 1); i > 0; i--) {
		progress = (i / (float)dist);
		tmp.a = (p[0].a + (p[1].a - p[0].a) * progress);
		tmp.b = (p[0].b + (p[1].b - p[0].b) * progress);
		*((int *)(iptr->addr + ((int)(tmp.a + 0.5) + DELTA_POS) * iptr->bpx
					+ ((int)(tmp.b + 0.5) + DELTA_POS) * iptr->sl))
			= (color_lerp(col_get(f.z, board->alts),
							col_get(t.z, board->alts), progress));
	}
}

void        render_iso(t_board *board, t_imgdata *iptr, t_dims *delta)
{
	const t_dims	max = {.x = board->pdims.x - 1, .y = board->pdims.y - 1};
	int 			x,
					y,
					max_h;

	max_h = (int)(board->alts.y
				+ ((board->pdims.x < board->pdims.y) ? 
					board->pdims.y : board->pdims.x) * 0.5);
	set_delta(delta, board);
	delta->x = 0;
	delta->y = 0;
	for(y = (max.y - 1); y > 0; y--)
	{
		for(x = (max.x - 1); x > 0; x--)
		{
			line_to(board->vertex[y][x].pos, board->vertex[y][x + 1].pos, board, iptr, max_h);
			line_to(board->vertex[y][x].pos, board->vertex[y + 1][x].pos, board, iptr, max_h);
		}
	}
}