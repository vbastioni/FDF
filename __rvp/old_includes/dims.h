#ifndef T_DIMS_H
# define T_DIMS_H

typedef struct  s_dims
{
    int         x;
    int         y;
}               t_dims;

typedef struct  s_dims2
{
    int         px;
    int         py;
    int         ix;
    int         iy;
}               t_dims2;

t_dims          dims_zero();
t_dims          dims_create(int x, int y);
t_dims2         dims_arr(t_dims i1, t_dims i2);

#endif