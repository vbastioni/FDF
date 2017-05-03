#include "renderer.h"

#include <mlx.h>

#include "color.h"
#include "defs.h"

void    render(t_board *board, t_imgdata *iptr, t_mode mode, t_wdata *wdata)
{
    t_dims  delta;

    if (mode == PAR)
        render_par(board, iptr, &delta);
    else if (mode == ISO)
        render_iso(board, iptr, &delta);
    mlx_put_image_to_window(wdata->mlx, wdata->win, iptr->img,
                                delta.x, delta.y);
}