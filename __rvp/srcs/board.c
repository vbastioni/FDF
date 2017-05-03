#include "board.h"

#include <stdlib.h>

t_board         *board_create()
{
    t_board     *ret;

    if (!(ret = (t_board *)malloc(sizeof(t_board))))
        return (NULL);
    ret->vertex = NULL;
    ret->pdims = dims_zero();
    ret->alts = dims_zero();
    return (ret);
}

int             board_prepare(t_board *board)
{
    if (!board)
        return (0);
    if (!(board->vertex = (t_vertex **)malloc(sizeof(t_vertex *)
                                                * board->pdims.y)))
        return (0);
    return (1);
}