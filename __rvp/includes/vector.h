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

void            vec_mult(t_vector *v, int n);
void            fvec_mult(t_fvector *v, int n);

#endif