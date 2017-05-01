#include "renderer.h"

#include <mlx.h>

#include "color.h"
#include "defs.h"

static void render_par(t_board *board, t_imgdata *iptr, t_dims *delta)
{
    int     x;
    int     y;
    char    *addr;

    delta->x = (board->pdims.x < BOARD_MAX_WIDTH &&
        (board->pdims.x * 2 - 1) > BOARD_MAX_WIDTH) ?
        ((BOARD_MAX_WIDTH - board->pdims.x) / 2) : 0;
    delta->y = (board->pdims.y < BOARD_MAX_HEIGHT &&
        (board->pdims.y * 2 - 1) > BOARD_MAX_HEIGHT) ?
        ((BOARD_MAX_HEIGHT - board->pdims.y) / 2) : 0;
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