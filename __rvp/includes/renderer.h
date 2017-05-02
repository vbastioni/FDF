#ifndef RENDERER_H
# define RENDERER_H

#include "board.h"
#include "imgdata.h"
#include "wdata.h"

typedef enum    e_mode
{
    PAR,
    ISO
}               t_mode;

void            render(t_board *board, t_imgdata *iptr, t_mode mode,
                        t_wdata *wdata);

#endif