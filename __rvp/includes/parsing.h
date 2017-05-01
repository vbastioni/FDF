#ifndef PREPARSING_H
# define PREPARSING_H

#include "board.h"
#include "wdata.h"

int     preparse_data(const char *filename, t_board **board);
void    **parse_data(const char *filename, t_board *board,
                        const t_wdata *wdata);

#endif