#include "renderer.h"

#include <mlx.h>

#include "color.h"
#include "defs.h"

#include <stdio.h>

void    render(t_board *board, t_imgdata *iptr, t_mode mode, t_wdata *wdata)
{
    t_dims  delta;

    printf("Will put img #%d\n", mode); //
    rdrs[0] = &render_par;
    rdrs[1] = &render_iso;
    rdrs[mode](board, iptr + mode, &delta);
    mlx_put_image_to_window(wdata->mlx, wdata->win, (iptr + mode)->img,
                            delta.x, delta.y);
/*
    if (mode == PAR)
    {
        render_par(board, iptr, &delta);
        mlx_put_image_to_window(wdata->mlx, wdata->win, iptr->img,
                                delta.x, delta.y);
    }
    else if (mode == ISO)
    {
        render_iso(board, iptr + 1, &delta);
        mlx_put_image_to_window(wdata->mlx, wdata->win, (iptr + 1)->img,
                                delta.x, delta.y);
    }
*/
}