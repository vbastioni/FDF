#ifndef T_DIMS_H
# define T_DIMS_H

typedef struct  s_dims
{
    int         x;
    int         y;
}               t_dims;

t_dims          dims_zero();
t_dims          dims_create(int x, int y);

#endif