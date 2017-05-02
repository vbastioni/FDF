#include "renderer_par.h"

#include "color.h"
#include "defs.h"

static void get_deltas(const t_board *board, t_dims *delta, t_dims *in)
{
    int     d;

    d = (BOARD_MAX_WIDTH - board->pdims.x);
    in->x = (d / (board->pdims.x - 1));
    delta->x = ((board->pdims.x * 2 - 1) > BOARD_MAX_WIDTH) ? (d / 2) :
        (BOARD_MAX_WIDTH - (in->x * (board->pdims.x - 1) + board->pdims.x)) / 2;
    d = (BOARD_MAX_HEIGHT - board->pdims.y);
    in->y = (d / (board->pdims.y - 1));
    delta->y = ((board->pdims.y * 2 - 1) > BOARD_MAX_HEIGHT) ? (d / 2) :
        (BOARD_MAX_WIDTH - (in->y * (board->pdims.y - 1) + board->pdims.y)) / 2;
}

static void render_right(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims inter)
{
    int         x;
    t_vertex    c;
    t_vertex    n;

    if ((pos.x + 1) == board->pdims.x)
        return ;
    c = board->vertex[pos.y][pos.x];
    n = board->vertex[pos.y][pos.x + 1];
    x = -1;
    while (++x < inter.x)
    {
    }
    (void)board;
    (void)iptr;
    (void)pos;
    (void)inter;
}

static void render_bottom(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims inter)
{
    int         x;
    t_vertex    c;
    t_vertex    n;

    if ((pos.y + 1) == board->pdims.y)
        return ;
    c = board->vertex[pos.y][pos.x];
    n = board->vertex[pos.y + 1][pos.x];
    x = -1;
    while (++x < inter.x)
    {
    }
    (void)board;
    (void)iptr;
    (void)pos;
    (void)inter;
}

static void render_diag(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims inter)
{
    int         x;
    t_vertex    c;
    t_vertex    n;

    if ((pos.x + 1) == board->pdims.x || (pos.y + 1) == board->pdims.y)
        return ;
    c = board->vertex[pos.y][pos.x];
    n = board->vertex[pos.y][pos.x + 1];
    x = -1;
    while (++x < inter.x)
    {
    }
    (void)board;
    (void)iptr;
    (void)pos;
    (void)inter;
}

void render_par(t_board *board, t_imgdata *iptr, t_dims *delta)
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
            addr = iptr->addr + pos.x * iptr->bpx * (inter.x + 1) +
                                pos.y * iptr->sl * (inter.y + 1);
            color_set(addr, board->vertex[pos.y][pos.x], 
                        iptr->endian, board->alts);
            render_right(board, iptr, pos, inter);
            render_bottom(board, iptr, pos, inter);
            render_diag(board, iptr, pos, inter);
        }
    }
}