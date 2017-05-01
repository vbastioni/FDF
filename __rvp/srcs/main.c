#include "defs.h"

#include <mlx.h>
#include <stdlib.h>//
#include "libft.h"//

#include "board.h"
#include "wdata.h"
#include "callback.h"
#include "preparsing.h"
#include "t2.h"

int     main(int ac, char **av)
{
    t_board     *board;
    t_wdata     *wdata;
    void        **imgs;

    if (ac < 2)
        return (1);
    if (!preparse_data(av[1], &board))
        return (1);
    wdata = create_window();
    imgs = parse_data(av[1], board, wdata);
    mlx_key_hook(wdata->win, handle_key, t2_create(wdata, imgs));
    mlx_loop(wdata->mlx);
    return (0);
}