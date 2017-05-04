#include "dims.h"

t_dims          dims_zero()
{
    t_dims      dims;

    dims.x = 0;
    dims.y = 0;
    return (dims);
}

t_dims          dims_create(int x, int y)
{
    t_dims      dims;

    dims.x = x;
    dims.y = y;
    return (dims);
}