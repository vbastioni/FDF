#ifndef BOARD_DATA_H
# define BOARD_DATA_H

#include "pixel.h"

typedef struct	s_board
{
    t_pixel	*pixel;
    int		height;
    int		width;
    int		min;
    int		max;
}		t_board;

t_board		*Board_create();

#endif
