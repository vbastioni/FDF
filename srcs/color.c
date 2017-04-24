#include "color.h"

int	color_lerp(int color_from, int color_to, float pct)
{
    if (color_from == color_to)
	return (color_from);
    return (color_from + ((color_to - color_from) * pct));
}
