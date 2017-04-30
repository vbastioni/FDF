#ifndef PREPARSING_H
# define PREPARSING_H

#include "board.h"

int     preparse_data(const char *filename, t_board **board);
void    **parse_data(const char *filename, t_board *board);

#endif