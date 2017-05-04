#ifndef IMGDATA_H
# define IMGDATA_H

#include "wdata.h"
#include "board.h"

typedef struct  s_imgdata
{
    t_wdata     *wdata;
    void        *img;
    char        *addr;
    int         bpx;
    int         sl;
    int         endian;
}               t_imgdata;

t_imgdata       create_img(const t_wdata *wdata);

#endif