#include "renderer.h"

static void render_par(t_board *board)
{
    (void)board;
}

static void render_iso(t_board *board)
{
    (void)board;
}

void    render(t_board *board, t_mode mode)
{
    if (mode == PAR)
        render_par(board);
    else if (mode == ISO)
        render_iso(board);
}