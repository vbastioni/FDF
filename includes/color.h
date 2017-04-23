#ifndef COLOR_H
# define COLOR_H

# define MIN_COLOR 0x0000FF
# define MAX_COLOR 0x00FF00

typedef unsigned int	UINT;
typedef unsigned char	UCHAR;

UINT	color_lerp(UINT color_from, UINT color_to, float pct);

#endif
