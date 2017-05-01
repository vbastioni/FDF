#ifndef PREPARSING_H
# define PREPARSING_H

#include "board.h"
#include "wdata.h"
#include "imgdata.h"

int         preparse_data(const char *filename, t_board **board);
t_imgdata   *parse_data(const char *filename, t_board *board,
                        const t_wdata *wdata);

#endif