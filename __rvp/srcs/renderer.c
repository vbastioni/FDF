#include "renderer.h"

#include <mlx.h>

#include "color.h"
#include "defs.h"

static void get_deltas(const t_board *board, t_dims *delta, t_dims *inter)
{
    int     n;
    int     d;

    d = (BOARD_MAX_WIDTH - board->pdims.x);
    n = (d / (board->pdims.x - 1));
    delta->x = ((board->pdims.x * 2 - 1) > BOARD_MAX_WIDTH) ?
        (d / 2) : ((d % n) / 2);
    d = (BOARD_MAX_HEIGHT - board->pdims.y);
    n = (d / (board->pdims.y - 1));
    delta->y = ((board->pdims.y * 2 - 1) > BOARD_MAX_HEIGHT) ?
        (d / 2) : ((d % n) / 2);
    (void)inter;
}

static void render_par(t_board *board, t_imgdata *iptr, t_dims *delta)
{
    int     x;
    int     y;
    char    *addr;
    t_dims  inter;

    get_deltas(board, delta, &inter);
    y = 0;
    while (y < board->pdims.y)
    {
        x = 0;
        while (x < board->pdims.x)
        {
            addr = iptr->addr + x * iptr->bpx + y * iptr->sl;
            color_set(addr, board->vertex[y][x], iptr->endian, board->alts);
            x++;
        }
        y++;
    }
}

static void render_iso(t_board *board)
{
    (void)board;
}

void    render(t_board *board, t_imgdata *iptr, t_mode mode, t_wdata *wdata)
{
    t_dims  delta;

    if (mode == PAR)
        render_par(board, iptr, &delta);
    else if (mode == ISO)
        render_iso(board);
    mlx_put_image_to_window(wdata->mlx, wdata->win, iptr->img,
                                delta.x, delta.y);
}