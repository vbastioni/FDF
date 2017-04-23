#include <stdlib.h>

#include "board.h"

t_board	    *Board_create()
{
    t_board *ret;

    if (!(ret = (t_board *)malloc(sizeof(t_board))))
	return (NULL);
    ret->pixel = NULL;
    ret->height = 0;
    ret->width = 0;
    return (ret);
}
