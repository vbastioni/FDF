#ifndef COLOR_H
# define COLOR_H

# define COLOR_MIN 0x0000FF
# define COLOR_MAX 0x00FF00
# define COLOR_DEFAULT 0xFFFFFF

typedef unsigned int	UINT;
typedef unsigned char	UCHAR;

int	color_lerp(int color_from, int color_to, float pct);

#endif
