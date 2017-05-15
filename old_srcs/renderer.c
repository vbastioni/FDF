#include "renderer.h"

#include <mlx.h>

#include "color.h"
#include "defs.h"

#include <stdio.h>

void    render(const t_board *board, t_imgdata *iptr, t_mode mode,
                t_wdata *wdata)
{
    t_dims  delta;

    rdrs[0] = &render_par;
    rdrs[1] = &render_iso;
    rdrs[mode](board, iptr + mode, &delta);
    mlx_put_image_to_window(wdata->mlx, wdata->win, (iptr + mode)->img, 0, 0);
}