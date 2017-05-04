#include "defs.h"

#include <mlx.h>

#include "board.h"
#include "wdata.h"
#include "callback.h"
#include "parsing.h"
#include "tX.h"
#include "renderer.h"

int     main(int ac, char **av)
{
    t_board     *board;
    t_wdata     *wdata;
    t_imgdata   iptr[3];

    if (ac < 2)
        return (1);
    if (!preparse_data(av[1], &board))
        return (1);
    wdata = create_window();
    if (!parse_data(av[1], board))
        return (1);
    iptr[0] = create_img(wdata);
    iptr[1] = create_img(wdata);
    iptr[2] = create_img(wdata);
    render(board, iptr, PAR, wdata);
    mlx_key_hook(wdata->win, handle_key, t3_create(board, wdata, iptr));
    mlx_loop(wdata->mlx);
    return (0);
}