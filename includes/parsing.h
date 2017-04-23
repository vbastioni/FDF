#ifndef PARSING_H
# define PARSING_H

#include "vertice.h"
#include "board.h"

t_board	*read_file(char *filename);
void	debug_vert(const t_vert *vert);

#endif
