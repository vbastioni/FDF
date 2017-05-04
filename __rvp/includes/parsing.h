#ifndef PREPARSING_H
# define PREPARSING_H

#include "board.h"
#include "wdata.h"
#include "imgdata.h"

int	preparse_data(const char *filename, t_board **board);
int	parse_data(const char *filename, t_board *board);

#endif