#ifndef WORKER_H
# define WORKER_H

int     preparse_data(const char *filename, t_board **board);
int     first_pass(const t_data *data, t_board *board);

#endif