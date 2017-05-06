#include "dims.h"

t_dims			dims_zero()
{
	t_dims		dims;

	dims.x = 0;
	dims.y = 0;
	return (dims);
}

t_dims			dims_create(int x, int y)
{
	t_dims		dims;

	dims.x = x;
	dims.y = y;
	return (dims);
}

t_dims2			dims_arr(t_dims i1, t_dims i2)
{
	t_dims2		ret;

	ret.px = i1.x;
	ret.py = i1.y;
	ret.ix = i2.x;
	ret.iy = i2.y;
	return (ret);
}