#ifndef RDRS_H
# define RDRS_H

void    (*rdrs[2])(t_board *board, t_imgdata *ptr, t_dims *delta) = 
{
    render_par,
    render_iso
};

#endif