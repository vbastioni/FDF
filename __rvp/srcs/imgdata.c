#include "imgdata.h"

#include <stdlib.h>
#include <mlx.h>

t_imgdata   *create_img(const t_wdata *wdata,
                        const t_board *board)
{
    t_imgdata   *ret;

    if (!(ret = (t_imgdata *)malloc(sizeof(t_imgdata))))
        return (NULL);
    ret->wdata = (t_wdata *)wdata;
    ret->img = mlx_new_image(wdata->mlx, board->pdims.x,
                                board->pdims.y);
    ret->addr = mlx_get_data_addr(ret->img, &ret->bpx, &ret->sl,
                                    &ret->endian);
    ret->bpx /= 8;
    return (ret);
}
