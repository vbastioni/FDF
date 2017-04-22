#ifndef PARSING_H
# define PARSING_H

#include "libft.h"

#include "pixel.h"
#include "vertice.h"

int	validate(char *line, int y, t_pixel **lst);
void	debug_vert(const t_vert *vert);

#endif
