#include "color.h"

#include "defs.h"

static  int abs(int n)
{
    return (n < 0 ? -n : n);
    return ((n < 0 && ((n + 1) > 0)) ? -n : n);
}

int  col_get(int v, t_dims alts)
{
    float pct;
    
    pct = (float)(v - alts.x) / (float)(alts.y - alts.x);
    return (color_lerp(COL_LOW, COL_HIGH, pct));
}

void        color_set(char *addr, t_vertex vert, int endian, t_dims alts)
{
    *((int *)addr) = (vert.color > -1 ? vert.color :
        col_get(vert.pos.z, alts)) << ((endian) ? 8 : 0);
}

typedef unsigned char   t_uchar;

int	color_lerp(int color_from, int color_to, double pct)
{
	if (color_from == color_to)
		return (color_from);
	t_uchar	cv[6];

	cv[0] = (color_from & 0xFF0000) >> 16;
	cv[3] = (color_to & 0xFF0000) >> 16;
	cv[1] = (color_from & 0xFF00) >> 8;
	cv[4] = (color_to & 0xFF00) >> 8;
	cv[2] = (color_from & 0xFF);
	cv[5] = (color_to & 0xFF);
    return ((((t_uchar)cv[0] + ((t_uchar)((cv[3] - cv[0]) * pct))) << 16) |
            (((t_uchar)cv[1] + ((t_uchar)((cv[4] - cv[1]) * pct))) << 8) |
            ((t_uchar)cv[2] + ((t_uchar)((cv[5] - cv[2]) * pct))));
}