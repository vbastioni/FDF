#include "dims.h"

void	Dims_set(t_dims *dims, int x, int y)
{
    if (!dims)
	return ;
    dims->x = x;
    dims->y = y;
}
