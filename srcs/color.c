#include "color.h"

UINT	color_lerp(UINT color_from, UINT color_to, float pct)
{
    if (color_from == color_to)
	return (color_from);
    return (color_from + ((color_to - color_from) * pct));
}
