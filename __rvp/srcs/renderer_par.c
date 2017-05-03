#include <math.h>

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
    if (in->x > in->y)
        in->x = in->y;
    else if (in->x < in->y)
        in->y = in->x;
    delta->y = ((board->pdims.y * 2 - 1) > BOARD_MAX_HEIGHT) ? (d / 2) :
        (BOARD_MAX_WIDTH - (in->y * (board->pdims.y - 1) + board->pdims.y)) / 2;
}

static void render_right(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims in)
{
    int         x;
    t_vertex    v[2];
    int         c[2];
    int         de;
    char        *addr;

    if ((pos.x + 1) == board->pdims.x || in.x == 0)
        return ;
    v[0] = board->vertex[pos.y][pos.x];
    v[1] = board->vertex[pos.y][pos.x + 1];
    c[0] = (v[0].color > -1 ? v[0].color : col_get(v[0].pos.z, board->alts))
            << (iptr->endian ? 8 : 0);
    c[1] = (v[1].color > -1 ? v[1].color : col_get(v[1].pos.z, board->alts))
            << (iptr->endian ? 8 : 0);
    x = 0;
    while (++x <= in.x)
    {
        de = (pos.x * (in.x + 1) + x) * iptr->bpx
                + pos.y * (in.y + 1) * iptr->sl;
        addr = iptr->addr + de;
        *((int *)addr) = color_lerp(c[0], c[1], (double)x / (in.x + 1));
    }
}

static void render_bottom(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims in)
{
    int         y;
    t_vertex    v[2];
    int         c[2];
    int         de;
    char        *addr;

    if ((pos.y + 1) == board->pdims.y || in.y == 0)
        return ;
    v[0] = board->vertex[pos.y][pos.x];
    v[1] = board->vertex[pos.y + 1][pos.x];
    y = 0;
    c[0] = (v[0].color > -1 ? v[0].color : col_get(v[0].pos.z, board->alts));
    c[1] = (v[1].color > -1 ? v[1].color : col_get(v[1].pos.z, board->alts));
    while (++y <= in.y)
    {
        de = (pos.x * (in.x + 1)) * iptr->bpx
                + (pos.y * (in.y + 1) + y) * iptr->sl;
        addr = iptr->addr + de;
        *((int *)addr) = color_lerp(c[0], c[1], (double)y / (in.y + 1));
    }
}

static void render_diag(t_board *board, t_imgdata *iptr,
                            const t_dims pos, const t_dims in)
{
    int         i;
    t_vertex    v[2];
    int         c[2];
    int         de;
    char        *addr;

    if ((pos.x + 1) == board->pdims.x || (pos.y + 1) == board->pdims.y
        || in.x == 0 || in.y == 0)
        return ;
    v[0] = board->vertex[pos.y][pos.x];
    v[1] = board->vertex[pos.y + 1][pos.x + 1];
    c[0] = (v[0].color > -1 ? v[0].color : col_get(v[0].pos.z, board->alts))
            << (iptr->endian ? 8 : 0);
    c[1] = (v[1].color > -1 ? v[1].color : col_get(v[1].pos.z, board->alts))
            << (iptr->endian ? 8 : 0);
    i = 0;
    while (++i <= in.x)
    {
        de = (pos.x * (in.x + 1) + i) * iptr->bpx
                + (pos.y * (in.y + 1) + i) * iptr->sl;        
        addr = iptr->addr + de;
        *((int *)addr) = color_lerp(c[0], c[1], (double)i / (in.y + 1));
    }
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