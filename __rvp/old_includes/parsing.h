#ifndef PREPARSING_H
# define PREPARSING_H

#include "board.h"
#include "wdata.h"
#include "imgdata.h"
#include "env.h"

int	preparse_data(const char *filename, t_env *env);
int	parse_data(const char *filename, t_env *env);

#endif