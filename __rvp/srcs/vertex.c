#include "vertex.h"

#include <stdlib.h>

t_vertex        *create_vert(t_vector pos, int color)
{
    t_vertex    *ret;

    if (!(ret = (t_vertex *)malloc(sizeof(t_vertex))))
        return (NULL);
    ret->pos = pos;
    ret->color = color;
    ret->next = NULL;
    return (ret);
}