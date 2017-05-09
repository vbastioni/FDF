#include "imgdata.h"

#include <stdlib.h>
#include <mlx.h>

#include "defs.h"

#include <stdio.h>

t_imgdata   create_img(const t_wdata *wdata)
{
    t_imgdata   ret;

    ret.wdata = (t_wdata *)wdata;
    ret.img = mlx_new_image(wdata->mlx, BOARD_MAX_WIDTH, BOARD_MAX_HEIGHT);
    ret.addr = mlx_get_data_addr(ret.img, &ret.bpx, &ret.sl, &ret.endian);
    printf("bpx: %d, sl: %d\n", ret.bpx, ret.sl);
    ret.bpx /= 8;
    return (ret);
}