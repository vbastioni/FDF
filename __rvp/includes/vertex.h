#ifndef VERTEX_H
# define VERTEX_H

#include "vector.h"

typedef struct      s_vertex
{
    t_vector        pos;
    int             color;
    struct s_vertex *next;
}                   t_vertex;

t_vertex            *create_vert(t_vector pos, int color);

#endif