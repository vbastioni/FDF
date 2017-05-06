#include "wdata.h"

#include <mlx.h>
#include <stdlib.h>

#include "defs.h"

t_wdata     *create_window()
{
    t_wdata *wdata;

    if (!(wdata = (t_wdata *)malloc(sizeof(t_wdata))))
        return (NULL);
    wdata->mlx = mlx_init();
    wdata->win = mlx_new_window(wdata->mlx, BOARD_MAX_WIDTH,
                    BOARD_MAX_HEIGHT, BOARD_NAME);
    return (wdata);
}