#ifndef IVECTOR_H
# define IVECTOR_H

#include "dims.h"

typedef struct  s_vector
{
    int         x;
    int         y;
    int         z;
}               t_vector;

typedef struct  s_fvector
{
    float       a;
    float       b;
}               t_fvector;

void            vector_set(t_vector *vect, t_dims pos, int alt);

#endif