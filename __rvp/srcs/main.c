#include "defs.h"

#include <mlx.h>

#include "board.h"
#include "wdata.h"
#include "callback.h"
#include "parsing.h"
#include "t2.h"
#include "renderer.h"

int     main(int ac, char **av)
{
    t_board     *board;
    t_wdata     *wdata;
    t_imgdata   *iptr;

    if (ac < 2)
        return (1);
    if (!preparse_data(av[1], &board))
        return (1);
    wdata = create_window();
    iptr = parse_data(av[1], board, wdata);
    render(board, iptr, PAR, wdata);
    mlx_key_hook(wdata->win, handle_key, t2_create(wdata, iptr));
    mlx_loop(wdata->mlx);
    return (0);
}