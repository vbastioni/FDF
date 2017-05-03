#include <math.h>

#include "renderer.h"
#include "defs.h"
#include "vector.h"

static void set_delta(t_dims *delta, t_board *board)
{
    t_dims      d;
    t_fvector   sz_vec;

    d = board->pdims;
    sz_vec.a = (((d.x < d.y) ? d.y : d.y) * 0.25f + 0.5f
                + board->alts.x + board->alts.y);
    sz_vec.b = (d.x + d.y) * cos(PI / 6.0f);
    (void)delta;    
}

void        render_iso(t_board *board, t_imgdata *ptr, t_dims *delta)
{
    (void)ptr;
    set_delta(delta, board);
}