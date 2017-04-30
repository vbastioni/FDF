#ifndef BOARD_H
# define BOARD_H

#include "vertex.h"
#include "dims.h"

typedef struct  s_board
{
    t_vertex    **vertex;
    t_dims      pdims;
}               t_board;

t_board         *board_create();
int             board_prepare(t_board *board);

#endif