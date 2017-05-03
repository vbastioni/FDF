#ifndef COLOR_H
# define COLOR_H

#include "vertex.h"
#include "dims.h"

void    color_set(char *addr, t_vertex vert, int endian, t_dims alts);
int     color_lerp(int c_a, int c_b, double progress);
int     col_get(int alt, t_dims alts);
#endif