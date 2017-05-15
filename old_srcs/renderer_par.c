#include <stdio.h>

#include <math.h>

#include "renderer.h"

#include "color.h"
#include "defs.h"


static void get_deltas(const t_board *board, t_dims *delta, t_dims *in)
{
	t_dims     d;

	d.x = (BOARD_MAX_WIDTH - board->pdims.x);
	in->x = (d.x / (board->pdims.x - 1));
	d.y = (BOARD_MAX_HEIGHT - board->pdims.y);
	in->y = (d.y / (board->pdims.y - 1));
	if (in->x > in->y)
		in->x = in->y;
	else if (in->x < in->y)
		in->y = in->x;
	delta->x = (BOARD_MAX_WIDTH - (in->x * (board->pdims.x - 1) + board->pdims.x)) / 2;
	delta->y = (BOARD_MAX_HEIGHT - (in->y * (board->pdims.y - 1) + board->pdims.y)) / 2;
	printf("inter: [%d, %d], d: [%d, %d], delta: [%d, %d]\n",
			in->x, in->y, d.x, d.y, delta->x, delta->y);
}

static void render_to(const t_board *board, const t_imgdata *iptr,
						t_dir dir, t_dims2 dms, t_dims delta)
{
	int			i;
	t_vertex	v[2];
	int			c[2];
	int			de;
	char		*addr;

	if ((dms.px + (dir != 1)) == board->pdims.x || dms.ix == 0
		|| (dms.py + (dir > 0)) == board->pdims.y || dms.iy == 0)
		return ;
	v[0] = board->vertex[dms.py][dms.px];
	v[1] = (board->vertex[dms.py + (dir > 0)][dms.px + (dir != 1)]);
    c[0] = (col_get(v[0], board->alts));
    c[1] = (col_get(v[1], board->alts));
	i = 0;
	while (++i <= (dms.ix))
	{
		de = ((dms.px * (dms.ix + 1) + (i * (dir != 1))) * iptr->bpx
				+ (dms.py * (dms.iy + 1) + (i * (dir > 0))) * iptr->sl)
				+ delta.x * iptr->bpx + delta.y * iptr->sl;
		addr = iptr->addr + de;
		*((int *)addr) = color_lerp(c[0], c[1], (double)i / (dms.ix + 1));
	}
}

void render_par(const t_board *board, const t_imgdata *iptr, t_dims *delta)
{
	t_dims  pos;
	char    *addr;
	t_dims  inter;

	get_deltas(board, delta, &inter);
	pos.y = -1;
	while (++pos.y < board->pdims.y)
	{
		pos.x = -1;
		while (++pos.x < board->pdims.x)
		{
			addr = iptr->addr 
					+ iptr->bpx * (delta->x + pos.x * (inter.x + 1))
                    + iptr->sl * (delta->y + pos.y * (inter.y + 1));
			color_set(addr, board->vertex[pos.y][pos.x],  iptr->endian,
						board->alts);
			render_to(board, iptr, RIG, dims_arr(pos, inter), *delta);
			render_to(board, iptr, BOT, dims_arr(pos, inter), *delta);
			render_to(board, iptr, DIA, dims_arr(pos, inter), *delta);
		}
	}
}