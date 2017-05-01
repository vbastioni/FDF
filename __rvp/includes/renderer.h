#ifndef RENDERER_H
# define RENDERER_H

#include "board.h"

typedef enum    e_mode
{
    PAR,
    ISO
}               t_mode;

void            render(t_board *board, t_mode mode);

#endif