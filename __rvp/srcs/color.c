#include "color.h"

#include "defs.h"

static  int abs(int n)
{
    return ((n < 0 && ((n + 1) > 0)) ? -n : n);
}

static int  col_get(int v, t_dims alts)
{
    return ((v < 0) ?
        (color_lerp(COL_LOW, COL_DEF, (double)abs(v) / alts.x)) :
        (color_lerp(COL_DEF, COL_HIGH, (double)v / alts.y)));
}

void        color_set(char *addr, t_vertex vert, int endian, t_dims alts)
{
    *((int *)addr) = (vert.color > -1 ? vert.color :
        col_get(vert.pos.z, alts)) << ((endian) ? 8 : 0);
}

int         color_lerp(int c_a, int c_b, double progress)
{
    return ((int)(c_a + (c_b - c_a) * progress));
}