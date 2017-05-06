#include "vector.h"

void    vec_mult(t_vector *v, int n)
{
    v->x *= n;
    v->y *= n;
    v->z *= n;
}

void    fvec_mult(t_fvector *v, int n)
{
    v->a *= n;
    v->b *= n;
}